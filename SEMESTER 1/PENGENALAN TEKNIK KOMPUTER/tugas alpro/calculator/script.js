let result = document.getElementById('result');

function clearResult() {
	result.value = '';
}

function calculate(value) {
	result.value += value;
}

function getResult() {
	result.value = eval(result.value);
}
