
Symbols
--------------
Here’s a comprehensive list of symbols and their meanings that you can use as a legend:

---

### **Logical Symbols**

|Symbol|Meaning|Description|
|---|---|---|
|¬p|Negation|"Not p"|
|p ∧ q|Conjunction|"p AND q"|
|p ∨ q|Disjunction|"p OR q" (inclusive OR)|
|p ⊕ q|XOR (Exclusive OR)|"p OR q, but not both"|
|p → q|Implication|"If p, then q"|
|p ↔ q|Biconditional|"p if and only if q"|

---

### **Set Theory Symbols**

|Symbol|Meaning|Description|
|---|---|---|
|∈|Element of|"x ∈ A" means "x is an element of A"|
|∉|Not an element of|"x ∉ A" means "x is NOT an element of A"|
|⊆|Subset|"A ⊆ B" means "A is a subset of B"|
|⊂|Proper subset|"A ⊂ B" means "A is a subset of B but not equal to B"|
|⊈|Not a subset|"A ⊈ B" means "A is not a subset of B"|
|∅|Empty set|A set containing no elements|
|U|Universal set|The set of all elements under discussion|
|∩|Intersection|"A ∩ B" is the set of elements in both A and B|
|∪|Union|"A ∪ B" is the set of elements in A or B (or both)|
|- or \|Set Difference|"A - B" or "A \ B" is the set of elements in A but not B|
|A^c|Complement|The set of elements not in A|

---

### **Number Sets**

|Symbol|Meaning|Description|
|---|---|---|
|ℕ|Natural Numbers|{0, 1, 2, 3, …} or {1, 2, 3, …}|
|ℤ|Integers|{…, -2, -1, 0, 1, 2, …}|
|ℚ|Rational Numbers|Numbers that can be expressed as a fraction (p/q)|
|ℝ|Real Numbers|All rational and irrational numbers|
|ℂ|Complex Numbers|Numbers of the form a + bi, where i² = -1|

---

### **Function & Relation Symbols**

|Symbol|Meaning|Description|
|---|---|---|
|f: A → B|Function notation|A function maps elements from set A to set B|
|f(a) = b|Function mapping|"f of a equals b"|
|∘|Function composition|"g ∘ f" means applying f first, then g|
|×|Cartesian Product|"A × B" is the set of ordered pairs (a, b)|

---

### **Quantifiers**

|Symbol|Meaning|Description|
|---|---|---|
|∀|Universal quantifier|"For all x, P(x) is true"|
|∃|Existential quantifier|"There exists x such that P(x) is true"|
|∄|Negated existential quantifier|"There does not exist x such that P(x) is true"|

---

### **Relations & Order**

|Symbol|Meaning|Description|
|---|---|---|
|=|Equality|"x = y" means x is equal to y|
|≠|Inequality|"x ≠ y" means x is not equal to y|
|<|Less than|"x < y" means x is less than y|
|>|Greater than|"x > y" means x is greater than y|
|≤|Less than or equal to|"x ≤ y" means x is less than or equal to y|
|≥|Greater than or equal to|"x ≥ y" means x is greater than or equal to y|

---

### **Miscellaneous Symbols**

|Symbol|Meaning|Description|
|---|---|---|
|∴|Therefore|Used to indicate a logical conclusion|
|∵|Because|Used to indicate a reason or cause|
|∑|Summation|"∑ f(x)" denotes the sum of values of f(x) over a range|
|∏|Product|"∏ f(x)" denotes the product of values of f(x) over a range|
|√|Square root|"√x" means the principal square root of x|
|∞|Infinity|Represents an unbounded limit|

---


The Foundations - Week 1
----------------------------------------
[Propositions: Building Blocks of Logic] - A **proposition** is a declarative sentence that is either true or false

**Ex.**
- Purdue Uni was founded in 1874
- 1869 + 0 = 1869
- Purdue CS Dept. is the oldest in the country
- Drilling for oil causes floods

**Ex. (NOT PROPOSITIONS)**
- What time is it?
- x+4=2x
- Stream that show!

variables used for propositions: *p, q, r*

[Constructing Propositions] - Compound propositions are constructed form logical connectives and other propositions

- Negation ¬  
	- the *negation* of a proposition p is denoted by ¬ p
	- EX. If p denotes "1+1=2" then ¬ p denotes "It is not the case that 1+1=2" or "1+1 is not equal to 2"
- Conjunction ∧  
	- the *conjunction* of propositions p and q is denoted by p ∧  q
	- EX. p: The movie is interesting, q: I'm staying at home THEN p ∧  q: The movie is interesting, AND I am staying at home
- Disjunction ∨  
	- The *disjunction* of propositions p or q is denoted p∨q
	- EX. p: "1+1=2" and q:"2+2=5", THEN p∨q denotes "1+1=2" or "2+2=5"

**NOTE: "OR Has 2 distinct meanings in English. Inclusive OR (One could be used OR both), and Exclusive OR (We only expect one OR to be used)"**

- Implication →  
	- If p and q are propositions, then p→q is a conditional statement of implication
	- EX. p="the card is diamond" and q="the card is red", THEN p→q denotes "the card is diamond, then it has to be red"
	- The p is the hypothesis (or premise) and q is the conclusion (or consequence) in p→q
	- If p is satisfied (true) and q is satisfied (true), then the statement (the obligation) is satisfied (true)  
	- When p is true but q is false, the obligation been evaded. The statement is false  
	- When p is false, the obligation will not be violated if q is false nor if q is true. The statement is true in either case
	- ***Converse, Inverse, and Contrapositive:***
	- q →p is the converse of p →q  
	- ¬ p → ¬ q is the inverse of p →q  
	- ¬q → ¬ p is the contrapositive of p →q  
	- EX. State the converse, inverse, and contrapositive of  “If x = 2, then x2=4.” 

- Biconditional
	- If p and q are propositions, the we can form the biconditional proposition p↔︎q; 
	- EX. p="This book is interesting" and q="I am staying at home", THEN p↔︎q denotes "The book is interesting if and only if I am staying at home"

*A biconditional is true iff both p and q have the same truth values.**
**An implication is only false if p is true and q is false.**

**Note:**
-  q →p is the *converse* of p →q  m ,
•⁠  ⁠¬ p → ¬ q is the *inverse* of p →q  
•⁠  ⁠¬q → ¬ p is the *contrapositive* of p →q  

| p   | q   | p → q |
| --- | --- | ----- |
| 1   | 1   | 1     |
| 1   | 0   | 0     |
| 0   | 1   | 1     |
| 0   | 0   | 1     |
fig. Truth table for the implies relation.

| p   | q   | p ↔️ q |
| --- | --- | ----- |
| 1   | 1   | 1     |
| 1   | 0   | 0     |
| 0   | 1   | 0     |
| 0   | 0   | 1     |
fig. Truth table for the biconditional relation.

##### Precedence of Logical Operators

| Operator | Precedence |
| -------- | ---------- |
| ¬        | 1          |
| ∧        | 2          |
| ∨        | 3          |
| →        | 4          |
| ↔️        | 5          |
*Note:* Quantifiers have higher precedence than all other operators.

*Tautologies:* Always true proposition
*Contradiction:* Always false proposition



---

## REDONE : Logic (Week 2)

### Propositions

- Definition: A declarative sentence that is either true or false.
- Examples: 
    - True: "Purdue University was founded in 1874."
    - False: "What time is it?"

### Logical Connectives

- Negation: ( ¬ p )
- Conjunction: ( p ∧ q )
- Disjunction: ( p ∨ q )
- Implication: ( p → q )
- Biconditional: ( p ↔q )

### Truth Tables

- Conjunction: 
    - ( p ∧ q ) is true if both ( p ) and ( q ) are true.
- Disjunction: 
    - ( p ∨ q ) is true if at least one of ( p ) or ( q ) is true.
- Implication: 
    - ( p → q ) is false only when ( p ) is true and ( q ) is false.

### Logical Equivalences

- Tautology: A proposition that is always true.
- Contradiction: A proposition that is always false.
- De Morgan's Laws: 
    - ( ¬(p ∨ q) ≡ ¬ p ∧ ¬ q )
    - ( ¬(p ∧ q) ≡ ¬ p ∨ ¬ q )

### Quantifiers

- Universal Quantifier: ( ∀ x P(x) ) means "for all ( x ), ( P(x) ) is true."
- Existential Quantifier: ( ∃ x P(x) ) means "there exists an ( x ) such that ( P(x) ) is true."

### Negating Quantified Expressions

- ( ¬ ∃ x P(x) ≡ ∀ x ¬ P(x) )
- ( ¬ ∀ x P(x) ≡ ∃ x ¬ P(x) )

### Nested Quantifiers

- The order of quantifiers matters: 
    - ( ∀ x ∃ y P(x, y) ) is not equivalent to ( ∃ y ∀ x P(x, y) ).
## Sets, Functions, and Relations (Week 3)
---------------------------------------------
### Sets

- Definition: An unordered collection of distinct objects (elements/members).
- Notation: 
    - If ( a ) is an element of set ( A ): ( a ∈ A )
    - If ( a ) is not an element of set ( A ): ( a ∌ A )

### Important Sets

- ( N ) = Natural numbers = {0, 1, 2, 3, ...}
- ( Z ) = Integers = {..., -3, -2, -1, 0, 1, 2, 3, ...}
- ( Z^+ ) = Positive integers = {1, 2, 3, ...}
- ( R ) = Set of real numbers
- ( R^+ ) = Set of positive real numbers
- ( Q ) = Set of rational numbers
- ( C ) = Set of complex numbers

### Interval Notation

- Closed Interval: ([a, b] = { x | a <= x <= b })
- Half-Open Intervals: 
    - ((a, b) = { x | a <= x < b })
    - ((a, b] = { x | a < x <= b })
- Open Interval: ((a, b) = { x | a < x < b })

### Set Equality

- Two sets ( A ) and ( B ) are equal if they have the same elements: ( A = B ).

### Universal Set and Empty Set

- Universal Set: ( U ) is the set containing everything under consideration.
- Empty Set: Denoted as ( Ø ) or ({}).

### Subsets

- Subset: ( A ⊆ B ) if every element of ( A ) is also in ( B ).
- Proper Subset: ( A \subset B ) if ( A ⊆ B ) and ( A \neq B ).

### Set Operations

- Union: ( A \cup B ) = set of elements in either ( A ) or ( B ).
- Intersection: ( A \cap B ) = set of elements in both ( A ) and ( B ).
- Complement: ( A^c = U - A ).
- Difference: ( A - B = { x | x ∈ A ∧ x ∌ B } ).

### Functions

- Definition: A function ( f ) from set ( A ) to set ( B ) assigns each element of ( A ) to exactly one element of ( B ).
- Notation: ( f: A → B ), ( f(a) = b ).

### Properties of Functions

- Injective (One-to-One): ( f(a) = f(b) ) implies ( a = b ).
- Surjective (Onto): For every ( b ∈ B ), there exists ( a ∈ A ) such that ( f(a) = b ).
- Bijective: A function that is both injective and surjective.

### Power Sets

- Definition: The power set ( P(A) ) is the set of all subsets of ( A ).
- Cardinality: If ( A ) has ( n ) elements, then ( |P(A)| = 2^n ).

### Cartesian Product

- Definition: The Cartesian product ( A \times B ) is the set of ordered pairs ( (a, b) ) where ( a ∈ A ) and ( b ∈ B ).

### Definition of a Relation

- A relation represents an association of objects from one set with objects from another set.
    - **Example**:
        - Students = {Chris, Bob, Mia}
        - Grades = {A, B, C, D, F}
        - Cars = {BMW, Ford, Volvo, Tesla}
        - Relation R1 = {(Chris, A), (Bob, B), (Mia, B)}

### Binary Relations

- A binary relation ( R ) from a set ( A ) to a set ( B ) is a subset ( R \subseteq A \times B ).
    - **Example**:
        - Let ( A = {0, 1, 2} ) and ( B = {a, b} )
        - ( R = {(0, a), (0, b), (1, a), (2, b)} ) is a relation from ( A ) to ( B ).

### Binary Relation on a Set

- A binary relation ( R ) on a set ( A ) is a relation from ( A ) to ( A ).
    - **Example**:
        - Let ( A = {a, b, c, d, e} ).
        - ( R = {(a, a), (a, b), (a, c), (e, e)} ) is a relation on ( A ).

### Binary Relations on Integers

- Examples of binary relations on integers:
    - ( R_1 = {(a, b) | a \leq b} )
    - ( R_2 = {(a, b) | a > b} )
    - ( R_3 = {(a, b) | a = b \text{ or } a = -b} )
    - ( R_4 = {(a, b) | a = b} )
    - ( R_5 = {(a, b) | a = b + 1} )
    - ( R_6 = {(a, b) | a + b \leq 3} )

### Reflexive Relations

- A relation ( R ) is reflexive if and only if ( (a, a) \in R ) for every element ( a \in A ).
    - **Reflexive Examples**:
        - ( R_1 = {(a, b) | a \leq b} )
        - ( R_3 = {(a, b) | a = b \text{ or } a = -b} )
    - **Not Reflexive Examples**:
        - ( R_2 = {(a, b) | a > b} )
        - ( R_5 = {(a, b) | a = b + 1} )

### Symmetric Relations

- A relation ( R ) is symmetric if ( (b, a) \in R ) whenever ( (a, b) \in R ) for all ( a, b \in A ).
    - **Symmetric Examples**:
        - ( R_3 = {(a, b) | a = b \text{ or } a = -b} )
        - ( R_4 = {(a, b) | a = b} )
    - **Not Symmetric Examples**:
        - ( R_1 = {(a, b) | a \leq b} )
        - ( R_5 = {(a, b) | a = b + 1} )

### Transitive Relations

- A relation ( R ) on a set ( A ) is transitive if ( (a, b) \in R ) and ( (b, c) \in R ) implies ( (a, c) \in R ) for all ( a, b, c \in A ).
    - **Transitive Examples**:
        - ( R_1 = {(a, b) | a \leq b} )
        - ( R_2 = {(a, b) | a > b} )
        - ( R_3 = {(a, b) | a = b \text{ or } a = -b} )
    - **Not Transitive Examples**:
        - ( R_5 = {(a, b) | a = b + 1} )
        - ( R_6 = {(a, b) | a + b \leq 3} )

### Equivalence Relations

- A relation on a set ( A ) is called an equivalence relation if it is reflexive, symmetric, and transitive.
- Two elements ( a ) and ( b ) that are related by an equivalence relation are called equivalent.
    - Notation: ( a \sim b ) denotes that ( a ) and ( b ) are equivalent elements with respect to a particular equivalence relation.

### Examples of Equivalence Relations

- **Example 4**: Jobs on processors
    
    - ( R_1 = {(a, b) | \text{jobs } a \text{ and } b \text{ are executed on the same processor}} )
        - Reflexive: True
        - Symmetric: True
        - Transitive: True
        - Conclusion: ( R_1 ) is an equivalence relation.
- **Example 5**: Relation on strings
    
    - ( R = {(a, b) | l(a) = l(b)} ), where ( l(x) ) is the length of string ( x ).
        - Reflexive: True
        - Symmetric: True
        - Transitive: True
        - Conclusion: ( R ) is an equivalence relation.

### Non-Equivalence Relation Example

- **Example 6**: "Divides" relation on positive integers
    - Not symmetric: For example, ( 2 \mid 4 ), but ( 4 \nmid 2 ).
    - Conclusion: The relation is not an equivalence relation.

### Combining Relations

- Given two relations ( R_1 ) and ( R_2 ), new relations can be formed using basic set operations:
    - ( R_1 \cup R_2 )
    - ( R_1 \cap R_2 )
    - ( R_1 - R_2 )
    - ( R_2 - R_1 )

### Composition of Relations

- Definition: Suppose ( R_1 ) is a relation from set ( A ) to set ( B ), and ( R_2 ) is a relation from ( B ) to set ( C ). The composition of ( R_1 ) and ( R_2 ), denoted ( R_1 \circ R_2 ), is a relation from ( A ) to ( C ).
    - If ( (x, y) ) is a member of ( R_1 ) and ( (y, z) ) is a member of ( R_2 ), then ( (x, z) ) is a member of ( R_1 \circ R_2 ).

### Visualizing Composition of Two Relations

- Example:
    - ( R_1 = {(a, p), (b, m), (b, p)} )
    - ( R_2 = {(m, B), (m, D), (n, A)} )
    - Resulting relation ( R_1 \circ R_2 = {(b, D), (b, B)} )

### Equivalence Classes

- Definition: The set of all elements in ( A ) that are related to an element ( x ) of ( A ) is called the equivalence class of ( x ).
    
    - Notation: ( [x]_R = {s | (x, s) \in R} )
- **Example 2**:
    
    - ( R = {(x, y) | x + y \text{ is even}} )
    - Equivalence classes:
        - ( [0] = { \text{all even numbers} } )
        - ( [1] = { \text{all odd numbers} } )

### Partition of a Set

- A partition of a set ( S ) is a collection of disjoint non-empty subsets of ( S ) that have ( S ) as their union.
    - Properties:
        1. ( A_i \cap A_j = \emptyset ), for ( i \neq j )
        2. ( A_i \neq \emptyset ), for ( i \in I )
        3. ( \bigcup_{i \in I} A_i = S )

### Theorem on Equivalence Classes and Partitions

- The equivalence classes of an equivalence relation ( R ) form a partition of ( S ).

---

Proof Techniques (Week 4)
----------------------------------------
**Introduction to Proof Techniques**

- Types of Proofs:
    - Direct Proofs
    - Proofs by Contraposition
    - Proofs by Contradiction
    - Proofs by Cases

**Definitions of Numbers**

- **Natural Numbers (ℕ)**: {0, 1, 2, 3, …}
- **Integers (ℤ)**: {..., -3, -2, -1, 0, 1, 2, 3, …}
- **Positive Integers (ℤ⁺)**: {1, 2, 3, …}
- **Real Numbers (ℝ)**: Includes all rational and irrational numbers (e.g., -π)
- **Positive Real Numbers (ℝ⁺)**: e.g., π
- **Rational Numbers (ℚ)**: e.g., 1/2

**Even and Odd Integers**

- An integer **n** is even if there exists an integer **k** such that **n = 2k**.
- An integer **n** is odd if there exists an integer **k** such that **n = 2k + 1**.
- Every integer is either even or odd.
- No integer is both even and odd.

**Direct Proof**

- To prove a conditional statement of the form **p → q**:
    - Assume that **p** is true.
    - Show that **q** must also be true.
- **Example**: Prove that if **n** is an odd integer, then **n²** is odd.
    - Assume **n** is odd: **n = 2k + 1** for some integer **k**.
    - Square both sides: **n² = (2k + 1)² = 4k² + 4k + 1 = 2(2k² + 2k) + 1**.
    - Thus, **n²** is odd.

**Proof of Rational Numbers**

- **Example**: Prove that the sum of two rational numbers is rational.
    - Assume **r** and **s** are two rational numbers.
    - There exist integers **p, q** and **t, u** such that **r = p/q** and **s = t/u**.
    - The sum is **(pu + qt) / (qu)**, where **qu ≠ 0**.
    - Thus, the sum of two rational numbers is rational.

**Proof by Contraposition**

- To prove **p → q**, show **¬q → ¬p**.
- **Example**: Prove that if **n** is an integer and **3n + 2** is odd, then **n** is odd.
    - Original statement: If **3n + 2** is odd, then **n** is odd.
    - Contrapositive: If **n** is even, then **3n + 2** is even.
    - Assume **n** is even: **n = 2k** for some integer **k**.
    - Then, **3n + 2 = 6k + 2 = 2(3k + 1)**, which is even.

**Proof by Contradiction**

- To prove that statement **p** is true, assume **¬p** and derive a contradiction.
- **Example**: Prove that **24x + 12y = 1** has no integer solution.
    - Assume **¬p**: There exists integers **x** and **y** such that **24x + 12y = 1**.
    - This leads to a contradiction since the left side is even and the right side is odd.

**Proof by Cases**

- **Example**: Show that if **x** and **y** are integers and both **x ∙ y** and **x + y** are even, then both **x** and **y** are even.
    - Assume **x** is odd.
    - Case 1: If **y** is odd, then **x ∙ y** is odd.
    - Case 2: If **y** is even, then **x + y** is odd.
    - Both cases lead to a contradiction, hence both **x** and **y** must be even.

**Common Errors in Proofs**

- Proof by example.
- Declaring a proof to be trivial.
- An indirect proof that starts with the assumption you want to derive.
- Using the same variable for two different values.

**Mathematical Induction**

- Used to prove statements that assert that **P(n)** is true for all positive integers **n**.
    - **Basis Step**: Verify that **P(1)** is true.
    - **Inductive Step**: Show **P(k) → P(k + 1)** is true for all positive integers **k**.

**Example of Induction**

- Prove that the sum of the first **n** positive odd integers is **n²**.
    - **Conjecture**: **Σ (2i + 1) = n²**.
    - Basis Step: **P(1)** is true.
    - Inductive Step: Assume **P(k)** is true, show **P(k + 1)** holds.

**Proving Inequalities**

- Use induction to prove inequalities such as **n < 2n** for all positive integers **n**.

**Challenging Problem**

- Show that there is a car which can complete a lap by collecting gas from the other cars on a circular track. **Recommended Exercises**
- KR 1.7: 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 33, 35, 37, 41, 43

**Further Topics in Mathematical Induction**

- Strong Induction
- Structural Induction

**Example of Strong Induction**

- Prove that every integer greater than 1 can be expressed as a product of prime numbers.

**Example of Structural Induction**

- Prove properties of recursively defined structures, such as trees or sequences.






# Week 10: Basic Counting

## Key Principles

### 1. Product Rule
- **Definition**: If a task consists of $n$ independent subtasks, the total number of ways to perform the task is:
  $$
  |A_1| \times |A_2| \times \ldots \times |A_n|
  $$
- **Example**:  
  How many 7-bit strings are there?  
  Each bit has 2 choices (0/1), so:  
  $$
  2^7 = 128
  $$

---

### 2. Sum Rule
- **Definition**: If tasks $A_1, A_2, \ldots, A_n$ are mutually exclusive, the total number of ways to perform one task is:
  $$
  |A_1| + |A_2| + \ldots + |A_n|
  $$
- **Example**:  
  Choosing between 5 movies, 2 concerts, or staying home:  
  $$
  5 + 2 + 1 = 8 \text{ choices}
  $$

---

### 3. Inclusion-Exclusion Principle
- **Definition**: For two overlapping sets $A$ and $B$:
  $$
  |A \cup B| = |A| + |B| - |A \cap B|
  $$
- **Example**:  
  How many 8-bit strings start with 1 **or** end with 00?  
  - Start with 1: $2^7 = 128$  
  - End with 00: $2^6 = 64$  
  - Overlap (start with 1 **and** end with 00): $2^5 = 32$  
  - Total: 
  $$
  128 + 64 - 32 = 160
  $$

---

### 4. Division Rule
- **Definition**: If $n$ identical outcomes are grouped into $d$ sets, the number of distinct outcomes is:
  $$
  \frac{n}{d}
  $$
- **Example**:  
  Seating 4 people around a circular table:  
  Total linear arrangements: $4! = 24$  
  Equivalent rotations: Divide by 4  
  $$
  \frac{24}{4} = 6 \text{ distinct arrangements}
  $$

---

## Pigeonhole Principle

### Basic Principle
- **Definition**: If $n$ objects are placed into $k$ containers where $n > k$, at least one container has ≥2 objects.
- **Example**:  
  Among 13 people, at least 2 share a birth month.

### Generalized Principle
- **Definition**: If $n$ objects are placed into $k$ containers, at least one container has ≥ $\lceil \frac{n}{k} \rceil$ objects.
- **Example**:  
  In 100 days, at least $\lceil \frac{100}{12} \rceil = 9$ people share a birth month.

---

## Permutations & Combinations

### Permutations
- **Definition**: Arrangements of $n$ distinct objects:
  $$
  P(n) = n!
  $$
- **Example**:  
  Arranging 3 books:  
  $$
  3! = 6 \text{ ways}
  $$
  
- **Theoram**
$$
  p(n, r) = \frac{n!}{(n-r)!}
  $$
### Combinations
- **Definition**: Selecting $r$ objects from $n$ without order:
  $$
  C(n, r) = \frac{n!}{r!(n-r)!}
  $$
- **Example**:  
  Choosing 2 toppings from 5:  
  $$
  C(5, 2) = \frac{5!}{2!3!} = 10
  $$

### Distinguishable Permutations
- **Definition**: Permutations of objects with duplicates:
  $$
  \frac{n!}{n_1! \cdot n_2! \cdots n_k!}
  $$
- **Example**:  
  Arranging "BANANA":  
  $$
  \frac{6!}{3!2!} = 60 \text{ ways}
 $$
## Applications

### 1. Poker Hands
- **Total 5-card hands from a 52-card deck**:  
 $$
  C(52, 5) = \frac{52!}{5!47!} = 2,598,960
  $$

### 2. Catalan Numbers
- **Parenthesizing $n+1$ terms**:  
  $$
  C_n = \frac{1}{n+1} C(2n, n)
  $$
- **Example**:  
  For $n=3$, $C_3 = \frac{1}{4} \cdot 20 = 5$ ways.

### 3. Combinations with Repetition
- **Choosing $r$ items from $n$ types with repetition**:  
  $$
  C(n + r - 1, r)
  $$
- **Example**:  
  Distributing 15 identical candies into 4 boxes:  
  $$
  C(15 + 4 - 1, 15) = C(18, 15) = 816
 $$






# Week 11: Discrete Probability

## Basic Concepts

- **Sample Space**: 
  - The sample space is the set of all possible outcomes of an uncertain event. In the context of CS 182, we primarily consider finite sample spaces, with one exception.
  - Each outcome \( x \) in the sample space has a probability \( p(x) \) that satisfies \( p(x) \geq 0 \).
  - The sum of the probabilities of all outcomes in the sample space equals one:
  $$
  \sum_{x \in S} p(x) = 1
  $$

- **Event**: 
  - An event is defined as a subset of the sample space. The probability of an event \( S \) is calculated as:
  $$
  p(S) = \sum_{x \in S} p(x)
  $$

- **Inclusion-Exclusion Principle**: 
  - This principle helps in calculating the probability of the union of two events \( A \) and \( B \):
  $$
  p(A \cup B) = p(A) + p(B) - p(A \cap B)
  $$

- **Complement Rule**: 
  - The probability of an event \( A \) can also be expressed in terms of its complement \( A^c \):
  $$
  p(A) = 1 - p(A^c)
  $$

---

## Uniform Distribution

- **Definition**: 
  - A uniform distribution is characterized by a sample space of size \( n \) where every outcome has an equal probability of \( \frac{1}{n} \).
  
- **Examples**:
  - **Rolling a Fair Die**: The probability of rolling any specific number (e.g., a 3) is \( \frac{1}{6} \).
  - **Drawing a Card from a Deck**: The probability of drawing a heart from a standard deck of cards is \( \frac{13}{52} = \frac{1}{4} \).
  
- **Probability of Event \( S \)**: 
  - The probability of an event \( S \) occurring is given by:
  $$
  p(S) = \frac{|S|}{n}
  $$
  where \( |S| \) is the number of favorable outcomes in event \( S \).

---

## Examples

### Example 1: Urn with Balls
**Problem**: An urn contains 4 blue balls and 5 red balls. What is the probability of drawing a blue ball?  
**Solution**:
- Total outcomes: \( 4 + 5 = 9 \).
- Favorable outcomes (blue balls): \( 4 \).
- Probability of drawing a blue ball:
  $$
  p(\text{Blue}) = \frac{4}{9}
  $$

---

### Example 2: Sum of Two Dice
**Problem**: What is the probability that the sum of two rolled dice equals 7?  
**Solution**:
- Total outcomes when rolling two dice: \( 6 \times 6 = 36 \).
- Favorable outcomes that sum to 7: 6 pairs: (1,6), (2,5), (3,4), (4,3), (5,2), (6,1).
- Probability:
  $$
  p(\text{Sum} = 7) = \frac{6}{36} = \frac{1}{6}
  $$

---

### Example 3: Lottery (Large Prize)
**Problem**: What is the probability of matching 4 digits in the correct order?  
**Solution**:
- Sample space size: \( 10^4 = 10,000 \).
- Only one winning combination exists.
- Probability of winning the large prize:
  $$
  p(\text{Win}) = \frac{1}{10,000}
  $$

---

### Example 4: Lottery (Small Prize)
**Problem**: What is the probability of matching exactly 3 digits?  
**Solution**:
- If exactly 3 digits are matched, one digit must be incorrect.
- There are 4 positions for the incorrect digit and 9 possible choices for the incorrect digit.
- Total favorable outcomes: \( 4 \times 9 = 36 \).
- Probability of winning the small prize:
  $$
  p(\text{Small Prize}) = \frac{36}{10,000} = \frac{9}{2500} = 0.0036
  $$

---

### Example 5: Poker Hand (Four of a Kind)
**Problem**: What is the probability of having four cards of the same rank in a 5-card hand?  
**Solution**:
- Total possible 5-card hands: 
  $$
  \binom{52}{5} = 2,598,960
  $$
- Favorable hands:
  - Choose the rank: \( 13 \) ways.
  - Choose the fifth card from the remaining \( 48 \) cards.
- Probability:
  $$
  p(\text{Four of a Kind}) = \frac{13 \times 48}{2,598,960} \approx 0.00024
  $$

---

## Conditional Probability

- **Definition**: 
  - The conditional probability of event \( E \) given event \( F \) is defined as:
  $$
  p(E|F) = \frac{p(E \cap F)}{p(F)} \quad \text{(if } p(F) > 0\text{)}
  $$

### Example 6: Bit String with Consecutive Zeros
**Problem**: A 4-bit string is generated at random. What’s the probability that it contains at least two consecutive zeros, given that its first bit is a 0?  
**Solution**:
- Sample space \( F \) (strings starting with 0): \( 8 \) outcomes.
- Favorable outcomes in \( F \): \( 5 \) (e.g., 0000, 0001, 0010, 0100, 0011).
- Probability:
  $$
  p(E|F) = \frac{5}{8}
  $$

---

## Independence

- **Definition**: 
  - Events \( E \) and \( F \) are independent if:
  $$
  p(E \cap F) = p(E)p(F)
  $$
  
- **Equivalent Definitions**:
  - $p(E|F) = p(E)$
  - $p(F|E) = p(F)$

### Example 7: Card Independence
- **With Replacement**: Selecting a Jack first and then an 8 is independent.
- **Without Replacement**: Selecting a Jack first and then an 8 is dependent (probabilities change).

---

## Bayes’ Theorem

- **Formula**:
  $$
  p(A|B) = \frac{p(B|A)p(A)}{p(B)}
  $$

### Example 8: Medical Testing
**Problem**: What is the probability of having a disease given a positive test result?  
**Solution**:
- Given:
  - \( p(D) = 0.001 \) (probability of disease),
  - \( p(T_d|D) = 0.99 \) (test detects disease),
  - \( p(T_d|D^c) = 0.02 \) (false positive rate).
- Total probability of a positive test:
  $$
  p(T_d) = p(T_d|D)p(D) + p(T_d|D^c)p(D^c) = 0.99 \times 0.001 + 0.02 \times 0.999 = 0.02097
  $$
- Posterior probability:
  $$
  p(D|T_d) = \frac{0.99 \times 0.001}{0.02097} \approx 0.047
  $$

---

## Expected Value

- **Definition**:
  - The expected value of a random variable \( X \) is calculated as:
  $$
  E(X) = \sum_{i=1}^n x_i p(X = x_i)
  $$

### Example 9: Fair Die Roll
**Problem**: What is the expected value \( X \) of one roll of a fair die?  
**Solution**:
$$
E(X) = \frac{1 + 2 + 3 + 4 + 5 + 6}{6} = 3.5
$$

### Example 10: Linearity of Expectation
- **Sum of Two Dice**: The expected value of the sum of two rolls is:
$$
E(X + Y) = E(X) + E(Y) = 3.5 + 3.5 = 7
$$

---

## Distributions

### Binomial Distribution
- **Formula**: The probability of \( k \) successes in \( n \) independent Bernoulli trials:
$$
P(X = k) = \binom{n}{k} p^k q^{n-k}
$$
- **Expected Value**: 
$$
E(X) = np
$$

### Geometric Distributio

- **Lifespan of a Lightbulb**: The probability that a lightbulb fails on the \( k \)-th trial:
$$
P(X = k) = (1-p)^{k-1}p
$$
- **Expected Value**: 
$$
E(X) = \frac{1}{p}
$$

---

## Practice Problems

### Exercise: Two Boxes with Balls
**Problem**: Given two boxes:
- Box 1: 2 green balls and 7 red balls.
- Box 2: 4 green balls and 3 red balls.
Bob selects a ball by first choosing one of the two boxes at random and then selecting one of the balls in this box at random. If Bob has selected a red ball, what is the probability that he selected a ball from the first box?  
**Solution**:
- \( p(\text{Box}_1) = p(\text{Box}_2) = \frac{1}{2} \)
- \( p(\text{Red}|\text{Box}_1) = \frac{7}{9} \), \( p(\text{Red}|\text{Box}_2) = \frac{3}{7} \)
- Total probability of drawing a red ball:
$$
p(\text{Red}) = p(\text{Red} \cap \text{Box}_1) + p(\text{Red} \cap \text{Box}_2) = \frac{7}{18} + \frac{3}{14} \approx 0.603
$$
- Posterior probability:
$$
p(\text{Box}_1|\text{Red}) = \frac{p(\text{Box}_1 \cap \text{Red})}{p(\text{Red})} = \frac{0.389}{0.603} \approx 0.645
$$



# Week 12: Graphs

## Introduction to Graphs
- **Definition**: A graph consists of a set of vertices $$V$$ and a set of edges $$E$$.
  - **Vertices**: Primitive objects that represent entities (e.g., $$a$$ and $$b$$).
  - **Edges**: Unordered pairs of vertices that represent connections (e.g., $$\{u, v\}$$).
- **Graph Representation**: Graphs are typically visualized as circles (vertices) connected by curves (edges).
- **Applications**: In practical scenarios, vertices can represent cities, and edges can represent driving distances or connections between them.

## Simple Graphs
- **Definition**: A simple graph is a type of graph that has:
  - **No Loops**: Each edge connects two distinct vertices.
  - **No Multiple Edges**: No two edges connect the same pair of vertices.
- **Terminology**: The term "graph" will generally refer to a simple graph unless specified otherwise.

## Multigraphs and Pseudographs
- **Multigraphs**: 
  - Definition: Graphs that allow multiple edges between the same pair of vertices.
  - Example: A graph where two cities are connected by multiple roads.
  
- **Pseudographs**: 
  - Definition: Graphs that allow both loops (edges that connect a vertex to itself) and multiple edges.
  - Example: A graph representing a network where a node can have self-loops and multiple connections.

## Graph Models
### Social Networks
- **Friendship Graph**: Represents relationships among individuals, where vertices are people and edges represent friendships.

### Academic Collaboration
- **Collaboration Graph**: Models the relationships between researchers based on co-authorship.
  - **Vertices**: Researchers.
  - **Edges**: Connect researchers who have co-authored papers.

### Biological Applications
- **Niche Overlap Graphs**: Represent competition between species in an ecosystem.
  - **Vertices**: Species.
  - **Edges**: Connect species that compete for the same food resources.

## Graph Terminology
- **Endpoints**: The vertices of an edge are called its endpoints.
- **Incident**: An edge and its endpoints are said to be incident to each other.
- **Adjacent**: The endpoints of an edge are adjacent to each other.
- **Nodes and Links**: Vertices and edges can also be referred to as nodes and links, respectively.
- **Degree of a Vertex**: The degree of a vertex is the number of edges incident to it. A loop contributes twice to the degree of its vertex.
  - Example: If vertex $$c$$ has three edges incident to it, then $$\text{deg}(c) = 3$$.

### Neighborhood
- **Neighbor**: An adjacent vertex is referred to as a neighbor.
- **Neighborhood**: The set of all neighbors of a vertex $$v$$ is denoted as $$N(v)$$.
- **Neighborhood of a Set**: If $$A$$ is a subset of $$V$$, then $$N(A)$$ is the set of all vertices in $$G$$ that are adjacent to at least one vertex in $$A$$.

## Handshake Theorem
- **Theorem Statement**: The sum of the degrees of all vertices in a graph equals twice the number of edges:
  $$\sum_{v \in V} \text{deg}(v) = 2E$$
- **Implication**: This theorem implies that the total degree of all vertices must be even since it equals twice the number of edges.

## Representing Graphs
### Matrix Representation
- **Adjacency Matrix**: A graph with $$n$$ vertices can be represented by an $$n \times n$$ matrix $$M$$ where:
  - $$M_{ij} = 1$$ if there is an edge between vertices $$v_i$$ and $$v_j$$, and $$0$$ otherwise.
- **Properties**:
  - The matrix is symmetric for undirected graphs.
  - Space complexity is $$O(n^2)$$, which can be inefficient for sparse graphs.

### List Representation
- **Edge List**: A graph can also be represented with an array of edge lists.
  - The $$i$$-th element of the array lists the vertices that are neighbors of vertex $$v_i$$.
- **Space Complexity**: The space complexity is $$O(m + n)$$ for a graph with $$n$$ vertices and $$m$$ edges, making it more efficient for sparse graphs.

## Special Types of Graphs
- **Complete Graph** $$K_n$$: A graph where every pair of distinct vertices is connected by a unique edge.
  - Example: $$K_4$$ has 4 vertices and 6 edges.
  
- **Cycle Graph** $$C_n$$: A graph that consists of a single cycle with $$n$$ vertices.
  - Example: $$C_4$$ is a square.

- **Wheel Graph** $$W_n$$: A graph that consists of a cycle with an additional central vertex connected to all vertices of the cycle.
  - Example: $$W_4$$ has a cycle of 4 vertices and a center vertex.

- **n-dimensional Hypercube** $$H_n$$: A graph that represents the binary strings of length $$n$$.
  - Properties: It has $$2^n$$ vertices and $$n \cdot 2^{n-1}$$ edges.

## Bipartite Graphs
- **Definition**: A simple graph $$G$$ is bipartite if its vertex set $$V$$ can be divided into two disjoint subsets $$V_1$$ and $$V_2$$ such that every edge connects a vertex in $$V_1$$ to a vertex in $$V_2$$.
- **Bipartition**: The pair $$(V_1, V_2)$$ is called a bipartition of the vertex set.
- **Coloring**: A simple graph is bipartite if and only if it can be colored using two colors such that no two adjacent vertices share the same color.

### Complete Bipartite Graph
- **Definition**: A complete bipartite graph $$K_{m,n}$$ has its vertex set partitioned into two subsets of sizes $$m$$ and $$n$$, with edges connecting every vertex in the first subset to every vertex in the second subset.

## Directed Graphs
- **Definition**: A directed graph (or digraph) $$G = (V, E)$$ consists of a set $$V$$ of vertices and a set $$E$$ of directed edges.
  - **Directed Edge**: Each edge is represented as an ordered pair of vertices, indicating direction (e.g., edge $$a \to b$$ starts at $$a$$ and ends at $$b$$).
- **Representations**: The matrix and list representations can also be adapted for directed graphs.

### In-Degree and Out-Degree
- **In-Degree**: The in-degree of a vertex $$v$$, denoted as $$\text{deg}^-(v)$$, is the number of edges that terminate at $$v$$.
- **Out-Degree**: The out-degree of a vertex $$v$$, denoted as $$\text{deg}^+(v)$$, is the number of edges that originate from $$v$$.
- **Theorem**: For a directed graph, the total number of edges can be expressed as:
  $$E = \sum_{v \in V} \text{deg}^+(v) = \sum_{v \in V} \text{deg}^-(v)$$

## Paths, Circuits, and Connectivity
- **Path**: A path is a sequence of edges that begins at a vertex and travels from vertex to vertex along edges.
  - **Length**: The length of a path is the number of edges in it.
- **Circuit (Cycle)**: A circuit is a path that starts and ends at the same vertex.
- **Simple Path/Circuit**: A path or circuit is simple if it does not contain the same edge more than once.

### Connectivity
- **Connected Graph**: A graph is connected if there is a path between every pair of vertices.
- **Connected Components**: The equivalence classes of connected vertices in a graph are called connected components.

## Euler Paths and Circuits
- **Euler Circuit**: A simple circuit that contains every edge of the graph exactly once.
- **Euler Path**: A simple path that contains every edge of the graph exactly once.
- **Theorem**: A connected multigraph has an Euler circuit if and only if every vertex has an even degree.
- **Existence of Euler Paths**: A connected multigraph has an Euler path but not an Euler circuit if and only if it has exactly two vertices of odd degree.

## Hamilton Paths and Circuits
- **Hamilton Path**: A simple path that visits every vertex exactly once.
- **Hamilton Circuit**: A simple circuit that visits every vertex exactly once.
- **Existence**: There is no known simple necessary and sufficient condition for the existence of Hamilton circuits.

## Planar Graphs and Graph Coloring
- **Planar Graph**: A graph that can be drawn in the plane without any edges crossing.
- **Euler’s Formula**: For a connected planar simple graph with $$e$$ edges and $$v$$ vertices, the number of regions $$r$$ in a planar representation is given by:
  $$r = e - v + 2$$
- **Corollaries**:
  - A connected planar graph satisfies $$e \leq 3v - 6$$.
  - A connected planar graph has at least one vertex of degree not exceeding five.

### Graph Coloring
- **Vertex Coloring**: Assigning colors to vertices such that no two adjacent vertices share the same color.
- **Chromatic Number**: The minimum number of colors needed to color a graph.
- **Applications**: Scheduling problems, map coloring, and resource allocation.

## Applications
- **Pathfinding**: Finding paths or circuits that traverse each street in a neighborhood exactly once.
- **Transportation Networks**: Optimizing routes for delivery or travel.
- **Utility Grids**: Ensuring efficient connections in power or water supply networks.
- **Scheduling**: Allocating resources or time slots in various applications, such as sports or events.







# Week 13: Trees 
---

## Introduction to Trees

- **Definition**: A tree is a connected graph without cycles. This means that there is exactly one path between any two vertices in the tree.
- **Forest**: A forest is a disjoint union of trees, meaning it consists of multiple trees that are not connected to each other.

### Example Analysis
- **Graph G3**: This graph is not a tree because it contains a simple circuit: 
  $$ e \rightarrow b \rightarrow a \rightarrow d \rightarrow e $$
- **Graph G4**: This graph is not a tree because it is not connected. Specifically, there is no path from vertex $$ a $$ to vertex $$ c $$

---

## Rooted Trees

- **Definition**: A rooted tree is a tree in which one vertex has been designated as the root. This root serves as the starting point for traversing the tree.
- **Direction of Edges**: In a rooted tree, every edge is directed away from the root. In some applications, edges may be directed towards the root.
- **Conversion**: An unrooted (or free) tree can be converted into different rooted trees by selecting a vertex as the root.

### Properties of Rooted Trees
- A rooted tree is an acyclic directed graph where the root vertex has a path to every other vertex.
- **Parent and Child**: The tail and head of an edge are referred to as parent and child, respectively.
- **Internal Vertex**: A vertex that has children is called an internal vertex.
- **Leaf**: A vertex that does not have any children is referred to as a leaf. Or called terminal vertex.

### Additional Terminology
- **Siblings**: Vertices that share the same parent are called siblings.
- **Descendants**: The descendants of a vertex are all vertices that can be reached from it.
- **Ancestors**: A vertex is considered an ancestor of its descendants.
- **Depth**: The depth of a vertex is defined as its distance from the root. For example, if the root is at depth 0, a vertex at depth 2 is two edges away from the root.

---

## Tree Terminology

- **Root**: Vertex A is the root of the tree.
- **Parent**: Vertex B is the parent of vertices D and E.
- **Children**: Vertex B has 2 children (D and E).
- **Siblings**: Vertex C is the sibling of vertex B.
- **Leaves**: Vertices D, E, F, G, and I are terminal vertices or leaves.
- **Level**: Vertex E is on level 2 (with the root A at level 0).
- **Height**: The height of the tree is defined as the length of the longest path from the root to a leaf.

---

## Tree Properties

### Property 1: Existence of Degree One Vertex
- **Statement**: Every tree has at least one vertex of degree one.
- **Proof**: 
  - Consider any vertex $$ v $$ in the tree. 
  - If the degree of $$ v $$ is greater than one, replace $$ v $$ with one of its neighbors $$ w $$. 
  - If $$ w $$ also has a degree greater than one, continue this process. 
  - This process cannot continue indefinitely because trees do not contain cycles, and it will eventually terminate at a vertex of degree one.

### Property 2: Relationship Between Vertices and Edges
- **Statement**: A tree with $$ n $$ vertices (where $$ n \geq 1 $$) has exactly $$ n - 1 $$ edges.
- **Proof (Method 1: Mathematical Induction)**:
  - **Base Case**: For $$ n = 1 $$, a tree with 1 vertex has 0 edges, which satisfies the property.
  - **Inductive Step**: Assume the property holds for some arbitrary $$ k $$. Let $$ T $$ be a tree with $$ k + 1 $$ vertices. 
    - Identify a vertex $$ v $$ of degree one in $$ T $$ and let $$ w $$ be its parent. 
    - Removing $$ v $$ and the edge connecting $$ w $$ to $$ v $$ results in a tree $$ T' $$ with $$ k $$ vertices. 
    - By the inductive hypothesis, $$ T' $$ has $$ k - 1 $$ edges. Therefore, $$ T $$ has $$ k $$ edges.

---

## Encoding Letters as Bit Strings

- **Naïve Encoding**:
  - Each letter is assigned a unique 5-bit binary string:
    - $$ a : 00000 $$
    - $$ b : 00001 $$
    - $$ c : 00010 $$
    - $$ d : 00011 $$
    - ...
    - $$ z : 11001 $$

### Huffman Coding
- **Question**: Can we improve upon naive encoding? Can trees assist in this process?
- **Solution**: Huffman Coding is a widely used algorithm for data compression that utilizes trees to create variable-length codes for characters based on their frequencies.

### Example of Huffman Coding
- Given symbols with their respective frequencies:
  - A : 0.08
  - B : 0.10
  - C : 0.12
  - D : 0.15
  - E : 0.20
  - F : 0.35
- **Encoded Values**:
  - A: 111
  - B: 110
  - C: 011
  - D: 010
  - E: 10
  - F: 00

### Average Bits Calculation
- The average number of bits used to encode a symbol can be calculated as follows:
  $$
  3 \cdot 0.08 + 3 \cdot 0.10 + 3 \cdot 0.12 + 3 \cdot 0.15 + 2 \cdot 0.20 + 2 \cdot 0.35 = 2.45
  $$

---

## Binary Tree Traversals

- **Definition**: Traversing a rooted tree systematically so that every vertex is visited exactly once is essential for exploring tree structures.
- **Standard Patterns**:
  - Preorder Traversal
  - Postorder Traversal
  - Inorder Traversal

### Traversal Definitions
1. **Preorder Traversal**:
   - Visit node $$ v $$.
   - Recursively perform preorder traversal on the left subtree.
   - Recursively perform preorder traversal on the right subtree.

2. **Postorder Traversal**:
   - Recursively perform postorder traversal on the left subtree.
   - Recursively perform postorder traversal on the right subtree.
   - Visit node $$ v $$.

3. **Inorder Traversal**:
   - Recursively perform inorder traversal on the left subtree.
   - Visit node $$ v $$.
   - Recursively perform inorder traversal on the right subtree.

### Example Traversals
- **Preorder**: The traversal order might be represented as: 
  $$
  (1, 2, 4, 5, 3, 6, 7)
  $$
- **Postorder**: The traversal order might be represented as: 
  $$
  (4, 5, 2, 6, 7, 3, 1)
  $$
- **Inorder**: The traversal order might be represented as: 
  $$
  (4, 2, 5, 1, 6, 3, 7)
  $$

---

## Expression Trees

- **Definition**: An expression tree is a binary tree representation of an arithmetic expression.
- **Example Expression**: 
  $$
  x + y * 2 - \frac{x}{3}
  $$
- **Steps to Construct**:
  1. Fully parenthesize the expression: 
     $$
     (((x + y) * 2) - (x / 3))
     $$
  2. Form vertices in the order of evaluation using the roots of subtrees as intermediate results.

### Traversal Notations
- **Prefix (Polish Notation)**: 
  $$
  + * + / A B C D E
  $$
- **Postfix (Reverse Polish Notation)**: 
  $$
  A B / C + D * E +
  $$

---

## Evaluating Prefix and Postfix Expressions

### Prefix Evaluation Example
- Expression: 
  $$
  / * 5 ^ 2 3 - 8 3
  $$
- Steps:
  - Evaluate to get the final result of $$ 8 $$.

### Postfix Evaluation Example
- Expression: 
  $$
  4 7 2 3 * - 4 ^ 9 3 / + -
  $$
- Steps:
  - Evaluate to get the final result of $$ 0 $$.

---

## Spanning Trees

- **Definition**: A spanning tree of a simple graph $$ G $$ is a subgraph of $$ G $$ that is a tree containing every vertex of $$ G $$.

### Properties
- A simple graph is connected if and only if it has a spanning tree. This means that if a graph has a spanning tree, all vertices are reachable from one another.

### Depth First Spanning Forest Construction
1. Assign each vertex of $$ g $$ a flag initialized to false.
2. For each vertex $$ v $$ of $$ g $$ whose flag is false, call $$ dfs(v) $$.

### Kruskal’s Algorithm
1. Sort the edges in increasing weight order.
2. Assign each vertex $$ v_i $$ a component label of $$ i $$.
3. Initialize an empty edge list $$ L $$.
4. For each edge $$ th $$ in the sorted list:
   - If $$ t $$ and $$ h $$ have different labels $$ i $$ and $$ j $$, add $$ th $$ to $$ L $$ and relabel all vertices that have label $$ i $$ with label $$ j $$.
5. Return $$ L $$.

### Example of Minimum Spanning Tree
- Total weight calculation for the minimum spanning tree:
  $$
  1 + 1 + 2 + 2 + 3 = 9
  $$

---
# Finite State Machines

## Language and Strings
- A **language** is a set of strings.
- A **string** is a sequence of characters.
  - **Examples**: "cat", "dog", "house", ...
- Strings and languages are defined over an **alphabet** \( \Sigma \), a set of characters.
  - Example: \( \Sigma = \{ a, b, c, \ldots, z \} \)

## Alphabets and Strings
- We will use alphabets with few elements:
  - **Strings**:
    - \( w = \text{abba} \)
    - \( v = \text{bbbaaa} \)
    - \( u = \text{ab} \)
  - Example Alphabet: \( \Sigma = \{ a, b \} \)

## String Operations
- **Concatenation**: 
  - If \( m \) and \( n \) are strings, then \( m \cdot n \) is the concatenation of \( m \) and \( n \).
  - Example: \( abba \cdot bbba = abba bbba \)

## String Length
- **Length**: The number of characters in a string.
  - Example: 
    - \( |w| = 4 \) for \( w = \text{abba} \)
    - \( |v| = 6 \) for \( v = \text{bbbaaa} \)

## Length of Concatenation
- If \( u \) is a string of length 3 and \( v \) is a string of length 5, then the length of the string \( uv \) formed by concatenating \( u \) and \( v \) is given by:
  $$ |uv| = |u| + |v| = 3 + 5 = 8 $$

## Empty String
- An **empty string** is a string with no letters, denoted as \( \lambda \).
- Observations:
  - \( | \lambda | = 0 \)

## String Operations
- **Reverse**: The reverse of a string \( w \) is denoted as \( w^R \).
  - Example: 
    - If \( w = \text{abba} \), then \( w^R = \text{abba} \)

## The * Operation (Kleene Star)
- The Kleene star operation \( L^* \) is the set of all possible strings from alphabet \( \Sigma \).
  - Example: 
    - If \( L = \{ a, b \} \), then \( L^* = \{ \lambda, a, b, aa, ab, ba, bb, aaa, aab, aba, abb, baa, bab, bba, bbb, \ldots \} \)

## Languages
- A **language** is any subset of \( \Sigma^* \).
  - Example: 
    - \( L = \{ \text{aaaaaa}, \text{ab}, \text{aa}, \text{baba}, \text{abba} \} \)

## Operations on Languages
- **Complement**: The complement of a language \( L \) is defined as:
  $$ \overline{L} = \Sigma^* - L $$

## Regular Expressions
- **Regular Expressions** are used to describe regular languages.
- **Primitive Regular Expressions**:
  - \( r_1, r_2 \) are regular expressions.
  - Operations include concatenation \( r_1 \cdot r_2 \), union \( r_1 + r_2 \), and Kleene star \( r^* \).

## Finite Automata
- A **Finite Automaton (FA)** is a theoretical machine used to recognize patterns within input.

### Vending Machine Example
- A vending machine accepts nickels, dimes, and quarters.
- If more than 30¢ is deposited, change is immediately returned.
- When there is 30¢ deposited and the "coke" button is pressed, the machine drops a coke.

### Transition Graph
- The transition graph represents the states and transitions of the finite automaton.

## Language Accepted by Finite Automaton
- The language \( L(M) \) is the set of all input strings accepted by \( M \).
  $$ L(M) = \{ \text{strings that bring } M \text{ to an accepting state} \} $$

## Nondeterministic Finite Automata (NFA)
- An NFA allows for multiple transitions for a given input from a state.
- **Acceptance**: An NFA accepts a string if there is at least one computation that leads to an accepting state.

## Properties of Regular Languages
- Regular languages can be represented by finite automata, regular expressions, and can be closed under operations like union, intersection, and complementation.
