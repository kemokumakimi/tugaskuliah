import flet as ft
import os
import threading
from pdf2docx import Converter
from docx2pdf import convert as docx2pdf_convert

def main(page: ft.Page):
    # =========================
    # KONFIGURASI HALAMAN
    # =========================
    page.title = "Document Converter Pro"
    page.theme_mode = ft.ThemeMode.DARK
    page.window_width = 700
    page.window_height = 600
    page.scroll = "auto"

    # =========================
    # STATE
    # =========================
    selected_files = []

    # =========================
    # UI COMPONENTS
    # =========================
    status_text = ft.Text("")
    current_file_text = ft.Text(size=12, color=ft.colors.GREY)

    progress_bar = ft.ProgressBar(width=500, value=0)
    overall_progress = ft.ProgressBar(width=500, value=0)

    file_list_view = ft.Column(scroll="auto", height=150)

    # =========================
    # UPDATE FILE LIST UI
    # =========================
    def update_file_list():
        file_list_view.controls.clear()
        for f in selected_files:
            file_list_view.controls.append(
                ft.Text(f"📄 {os.path.basename(f)}")
            )
        page.update()

    # =========================
    # FILE PICKER
    # =========================
    def pick_files(e):
        file_picker.pick_files(allow_multiple=True)

    def on_file_selected(e: ft.FilePickerResultEvent):
        if e.files:
            for f in e.files:
                selected_files.append(f.path)
        update_file_list()

    file_picker = ft.FilePicker(on_result=on_file_selected)
    page.overlay.append(file_picker)

    # =========================
    # DRAG & DROP
    # =========================
    def on_drop(e: ft.DragTargetEvent):
        if e.data:
            paths = e.data.split(",")
            for path in paths:
                selected_files.append(path.strip())
            update_file_list()

    drop_area = ft.Container(
        content=ft.Column(
            [
                ft.Icon(ft.icons.UPLOAD_FILE, size=40),
                ft.Text("Drag & Drop file di sini"),
                ft.Text("atau klik tombol Upload", size=12)
            ],
            alignment=ft.MainAxisAlignment.CENTER,
            horizontal_alignment=ft.CrossAxisAlignment.CENTER
        ),
        border=ft.border.all(2, ft.colors.BLUE),
        border_radius=10,
        height=150,
        alignment=ft.alignment.center
    )

    # =========================
    # KONVERSI LOGIC
    # =========================
    def convert_files():
        total = len(selected_files)
        if total == 0:
            status_text.value = "❌ Tidak ada file"
            status_text.color = ft.colors.RED
            page.update()
            return

        for i, file_path in enumerate(selected_files):
            try:
                current_file_text.value = f"Memproses: {os.path.basename(file_path)}"
                progress_bar.value = 0
                page.update()

                ext = file_path.lower()

                # ================= PDF -> DOCX =================
                if ext.endswith(".pdf"):
                    output = os.path.splitext(file_path)[0] + ".docx"
                    cv = Converter(file_path)

                    # Simulasi progress per halaman
                    total_pages = len(cv.pages)
                    for p in range(total_pages):
                        cv.convert(output, start=p, end=p+1)
                        progress_bar.value = (p + 1) / total_pages
                        page.update()

                    cv.close()

                # ================= DOCX -> PDF =================
                elif ext.endswith(".docx"):
                    output = os.path.splitext(file_path)[0] + ".pdf"

                    # docx2pdf tidak punya progress → fake smooth progress
                    for p in range(10):
                        progress_bar.value = (p + 1) / 10
                        page.update()
                    
                    docx2pdf_convert(file_path, output)

                else:
                    continue

            except Exception as e:
                status_text.value = f"❌ Error di {os.path.basename(file_path)}: {str(e)}"
                status_text.color = ft.colors.RED
                page.update()
                return

            # ================= UPDATE PROGRESS TOTAL =================
            overall_progress.value = (i + 1) / total
            page.update()

        status_text.value = "✅ Semua file berhasil dikonversi!"
        status_text.color = ft.colors.GREEN
        current_file_text.value = ""
        page.update()

    # =========================
    # THREAD WRAPPER
    # =========================
    def start_conversion(e):
        thread = threading.Thread(target=convert_files)
        thread.start()

    # =========================
    # UI LAYOUT
    # =========================
    page.add(
        ft.Column(
            [
                ft.Text("🚀 Document Converter Pro", size=26, weight="bold"),

                drop_area,

                ft.ElevatedButton(
                    "Upload File",
                    icon=ft.icons.UPLOAD,
                    on_click=pick_files
                ),

                ft.Text("📂 File yang dipilih:"),
                file_list_view,

                ft.ElevatedButton(
                    "Mulai Konversi",
                    icon=ft.icons.PLAY_ARROW,
                    on_click=start_conversion
                ),

                ft.Text("Progress File Saat Ini:"),
                progress_bar,

                ft.Text("Progress Total:"),
                overall_progress,

                current_file_text,
                status_text
            ],
            horizontal_alignment=ft.CrossAxisAlignment.CENTER,
            spacing=15
        )
    )

# =========================
# RUN APP
# =========================
if __name__ == "__main__":
    ft.app(target=main)