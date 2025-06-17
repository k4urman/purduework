# WEEK 1
-----------
## Chapter 1: IN CLASS
**Proposition**: A declarative sentence that is either true or false.

| Symbol | Meaning            | Description             |
| ------ | ------------------ | ----------------------- |
| ¬p     | Negation           | "Not p"                 |
| p ∧ q  | Conjunction        | "p AND q"               |
| p ∨ q  | Disjunction        | "p OR q" (inclusive OR) |
| p ⊕ q  | XOR (Exclusive OR) | "p OR q, but not both"  |
| p → q  | Implication        | "If p, then q"          |
| p ↔ q  | Biconditional      | "p if and only if q"    |
##### Negation

| p   | ¬p  |
| --- | --- |
| T   | F   |
| F   | T   |
##### And (Conjuction)

| p   | q   | p ∧ q |
| --- | --- | ----- |
| T   | T   | T     |
| T   | F   | F     |
| F   | T   | F     |
| F   | F   | T     |
##### Or (Disjunction)

| p   | q   | p ∨ q |
| --- | --- | ----- |
| T   | T   | T     |
| T   | F   | T     |
| F   | T   | T     |
| F   | F   | F     |
##### Exclusive Or

| p   | q   | p ⊕ q |
| --- | --- | ----- |
| T   | T   | F     |
| T   | F   | T     |
| F   | T   | T     |
| F   | F   | F     |
##### Implication

| p   | q   | p → q |
| --- | --- | ----- |
| T   | T   | T     |
| T   | F   | F     |
| F   | T   | T     |
| F   | F   | T     |
##### Biconditional
$$

$$

| p   | q   | p ↔ q |     |
| --- | --- | ----- | --- |
| T   | T   | T     |     |
| T   | F   | F     |     |
| F   | T   | F     |     |
| F   | F   | T     |     |

**Converse**: q → p
**Inverse**: ¬p → ¬q
**Contropositive**: ¬q → ¬p

**Tautology** - A compound proposition that always defaults to TRUE.
**Contradiction**: A compound porposition that defaults to FALSE.
**Contingency** - Neither Taultology or a Contradiction.
### PSO!
1. (p → r) ∨ (q → r) = (p ∧ q) → r ?

| p   | q   | r   | a.(p→r) | b.(q→r) | c.(p∧q) | a∨b | c→r |
| --- | --- | --- | ------- | ------- | ------- | --- | --- |
| T   | T   | T   | T       | T       | T       | T   | T   |
| T   | T   | F   | F       | F       | T       | F   | F   |
| T   | F   | T   | T       | T       | F       | T   | T   |
| T   | F   | F   | F       | T       | F       | T   | T   |
| F   | T   | T   | T       | T       | F       | T   | T   |
| F   | T   | F   | T       | F       | F       | T   | T   |
| F   | F   | T   | T       | T       | F       | T   | T   |
| F   | F   | F   | T       | T       | F       | T   | T   |
2. Tautology: Will always be true. Are the following tautolgies?
	- (¬p∧(p→q))→ ¬q  IS NOT

| p   | q   | ¬p  | (p→q) | (¬p∧(p→q)) | ¬q  | (¬p∧(p→q))→ ¬q |
| --- | --- | --- | ----- | ---------- | --- | -------------- |
| T   | T   | F   | T     | F          | F   | T              |
| T   | F   | F   | F     | F          | T   | T              |
| F   | T   | T   | T     | T          | F   | F              |
| F   | F   | T   | T     | T          | T   | T              |

- (¬q∧(p→q))→ ¬p IS INDEED

| p   | q   | ¬q  | (p→q) | (¬q∧(p→q)) | ¬p  | (¬q∧(p→q))→ ¬p |
| --- | --- | --- | ----- | ---------- | --- | -------------- |
| T   | T   | F   | T     | F          | F   | T              |
| T   | F   | T   | F     | F          | F   | T              |
| F   | T   | F   | T     | T          | T   | T              |
| F   | F   | T   | T     | T          | T   | T              |

3. Evalute
	- log4(64) = 3
	- log4(32) = 5/2
	- log9(3) = 1/2
	- log2(3sqrt(16)) = 4/3
	- log3(1/81) = -4
	- log1/2(sqrt(2)) = -1/2

4. find base n such that log n (3) = -3/2  -> 1/3sqrt(9)
5. Evalute log 2sqrt(2) (1/64) = -4
6. Find positive integer n for which:
		log2(1) + log2(2) + log2(3) +... + log2(n) = 2026



