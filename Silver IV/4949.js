const [...input] = require("fs")
	.readFileSync("/dev/stdin")
	.toString()
	.trim()
	.split("\n");
input.pop();

const checker = (text) => {
	const stack = [];

	for (let i of text) {
		switch (i) {
			case "[":
				stack.push("[");
			case "(":
				stack.push("(");
			case "]":
				if (stack.at(-1) !== "[") break;
				stack.pop();
			case ")":
				if (stack.at(-1) !== "(") break;
				stack.pop();
		}
	}

	if (stack.length !== 0) return "no";

	return "yes";
};

let answer = "";
for (let i of input) answer += `${checker(i)}\n`;

console.log(answer);
