from distutils.core import setup, Extension
import numpy as np

source_ext = '.c'
cmdclass = {}


ext_modules = [Extension("freenect", ["freenect" + source_ext],
                         libraries=['usb-1.0', 'freenect', 'freenect_sync'],
                         runtime_library_dirs=['/usr/local/lib',
                                               '/usr/local/lib64',
                                               '/usr/lib/'],
                         extra_compile_args=['-fPIC', '-I', '../../include/',
                                             '-I', '/usr/include/libusb-1.0/',
                                             '-I', '/usr/local/include/libusb-1.0',
                                             '-I', '/usr/local/include',
                                             '-I', '../c_sync/',
                                             '-I', np.get_include()])]
setup(name='freenect',
      cmdclass=cmdclass,
      ext_modules=ext_modules)
