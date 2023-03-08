# Infinities, multiplicative inverses and finite fields

Let's say we want: 1 + 1 + 1 + 1 + ... + 

That's to say: Sum[1, from n = 1 to infinity], which is the same as:

1 * infinity = x

So, you know, that means x = infinity.

But are we sure? Can we re-arrange the equation and would it still make sense?

If we divide both sides by infinity, what do we get?


(1 * infinity) / infinity = x / infinity

As you know, for the RHS, anything over infinity is zero (approaches zero), given that:

1/1 > 1/2 > 1/3 > ... > 1/infinity > 0

And applying squeeze theorem (or applying limits, as 1/n as n approaches infinity = zero), therefore 1/infinity = zero, and zero * anything (i.e. any other numerator) also equals zero.

Therefore, RHS = zero.

But what happens to the LHS?

LHS = 1 * infinity / infinity

...

Then does the infinity cancel out?

LHS = 1

Therefore: 1 = 0. Which is a contradiction.

The reason why it's a contradiction is: you can't divide infinity by infinity -- it's undefined, as infinity isn't a number (NaN = not a number). This is because you can always have 1 more element or number added to infinity -- i.e. infinity + 1 = infinity, so you don't know the exact value of infinity, and the numerator infinity may be different to the denominator's infinity.

In mathematics, this means there is no "multiplicative inverse" for Reals (real numbers) when one of the numbers is infinity.

# Modulo 2 - binary arithmetic (finite field)

Let's say we do the same again... but with modulo 2 (binary arithmetic)

1 + 1 + 1 + 1 + ... +  mod 2

The result is whether there's an even or add amount of 1's being added.

If even, it's zero.

If odd, it's 1.

Expressing this in terms of arithmetic, without using odd or even,

Equation 1 = Sum[1, from n = 0 to infinity] mod 2

Therefore, we can re-use the summation to multiplication rule, and modulo 2 the result, so we'd either have a 0 bit or 1 bit.

For the 0 bit:

1 * 0 = x

Therefore, x = 0.

But, the multiplicative inverse:

1 * (0/0) = x / 0


RHS = an asymptote (i.e. infinity)

LHS = undefined, as 0/0 is undefined.

So there is no multiplicative inverse for modulo 2.

For the 1 bit:

1 * 1 = x

multiplicative inverse:

1 * 1/1 = x / 1

RHS = x

LHS = 1

Therefore, x = 1.

Thus, a multiplicative inverse exists if the bit is 1.

# Wait, you must be wrong...?

The reason is simple.

The mathematics for multiplication in modulo 2 arithmetic (binary) is this:

Boolean "AND" operator.

0 AND 0 = 0

0 AND 1 = 0

1 AND 0 = 0

1 AND 1 = 1

You can easily verify this is true, by substituting the "AND" operator with the usual "multiply" operator that you're normally familiar with. The answer is the same.

This means that the result is a mapping of 3-to-1 -- when it equals 0, and 1-to-1 when it equals 1.

Thus the inverse exists only if the result is 1.

QED.

# Argument from Marilyn Vos Savant vs Andrew Wiles (don't need multiplicative inverse)

(Not sure if this accurate, it's based off the internet)

Marilyn Vos Savant famously argued that Andrew Wiles' proof of Fermat's Last Theorem doesn't work because it uses something that "wraps infinity around" -- such as the modularity theorem. 

The argument is that there might not exist a multiplicative inverse, especially since Fermat's Last Theorem deals with infinity, so it should be thrown out as a valid proof of FLT.

(Recap: Fermat's Last Theorem: c^n = a^n + b^n, where c, a, b, are all integers, and n is an integer >= 3, where the theorem states you can't find a solution for a, b, c)

The reason why Marilyn Vos Savant was wrong was because the proof didn't need the multiplicative inverse.

As you can see here, with regards to modulo 2:

1 * 0 = x

x = 0

...

1 * 1 = x

x = 1

They're both valid solutions to binary arithmetic, and "wrap infinity around modulo 2", and so it can deal with the summation of "1" (from n = 0 to infinity) and give you a valid answer in that field.

Whereas, if you used the Integers (Z) or Reals (R), you won't get an answer, since it's infinity, and infinity is not a number.

# Clock - 12 hours (simple field which a multiplicative inverse = multiplication -- i.e. symmetric)


Imagine you have an analog clock. It's a modulo 12 system.

Now you have the number: 2 * 4. What's the answer? It's 8.

Now you want the inverse: 8 / 2. What's the answer? it's 4. 

So far so good.

But what if you did this? 8 * 2. What's the answer? 8 * 2 = 16 .... but modulo 12 ... = 4.

That is, the hour hand goes around past the 12 o'clock, and goes back to 4 o'clock.

Therefore, at least with this set of numbers (2, 4) in modulo 12, they have a multiplicative inverse, and the multiplicative inverse is ALSO the same as the multiplication operator.

This is a very useful property to have in cryptography. Because if reversing the output of a function f^(-1)(x) is as easy as applying the original function f(x) to it, it saves alot of time verifying that the function is secure "both" ways.


# Feistel Ciphers... aka DES or Blowfish


In Feistel ciphers, they use a function that gives an output, which is then fed back to another call of the function.

i.e. they compose a series of functions, such as f(f(x)). (You can think of it as this: input -> function -> output -> function -> output 2 -> function, etc..)

Each time it's fed into the function it's called a "Round".

Usually they have a dozen or so rounds to make it secure.

But what is the useful property of feistel ciphers?  
  
Their inverse is the same as the non-inverse. i.e. you don't have a different inverse function, so they're easy to prove they're secure. (i.e. no backdoors or cheap tricks exist in the inverse function).

# Why multiple rounds to guarantee security?

The reason why multiple rounds guarantees security, is because it increases the cycle of randomness.

Say for example, you have a PRNG that works on a 32-bit integer, and has a 2^16 cycle -- i.e. the number of numbers it outputs before it starts repeating itself again. If you want to extend this to at least 2^32, you need to chain up calls to the PRNG function multiple times (at least 2^16 times more).

Think of it another way: it's a transformation from 1 dimension to 2 dimensions, and back to a 1 dimensional value, each time the function is chained up.

Mathematically: Real^1 * Real^1 = Real^2, which then gets transformed back to Real^1.

# Multiple dimensions mathematics... to infinity and beyond...

A very simple example is this:

2^2 = 2 * 2 = 4.

How do we display this?  

On a number line, it's the number 4.

On a two dimensional plane (x, y graph), it's 2 x 2 square, with an area of 4.

Let's take a look at 2^3:

2^3 = 2 * 2 * 2 = 8

So on a single number line, it's 8 -- i.e. Real^1.

On a 3D graph, it's 2x2x2 cube, i.e. the result in Real^3 (x, y, z) = (2, 2, 2).

If you take a look at L-norms, then you know:

L-1 norm = taxicab distance. e.g. if you had to traverse a city which had square blocks by blocks, then you would count the number of sides of the blocks you had to drive past to get to the destination, since you can't just travel in a straight line (like a bird or a plane).

L-2 norm = euclidean distance. (i.e. travelling between the two points in a straight line, e.g. hypotenuse in a right angle triangle).

L-infinity norm = take the max value of all the elements in the vector. e.g. L-inf-norm((2, 2, 3)) = 3.

These norms, calculate (transform) the various multidimensional numbers into a scalar.

There are obviously other mathematical functions that do similar transformations: dot product, (inverse) fourier transforms, etc. (Look them up on the internet if you're interested).

Anyway, one of the things I'd point out now is that if you had 2^infinity, and you had to express that as a scalar value, is there some way you could "compress" the result, such that it's still valid mathematics, similar to a modulo (finite field)?

Yes. L-inf norm. The L-inf norm of 2^infinity is just 2.

So there are tools in mathematics to work around the problem of infinity.

