const sieve = max => {
  // Assume every number is prime to start
  const sieve = new Array(max).fill(true)

  // Go from 2 to the square root of `max`
  for (let i = 2; i < Math.sqrt(max); i++) {
    // If `i` is marked as a prime, we know every
    // multple of `i` starting at `i^2` is not prime.
    if (sieve[i]) {
      for (let j = Math.pow(i, 2); j < max; j += i) {
        sieve[j] = false
      }
    }
  }

  const primes = [];

  for (let i = 0; i < sieve.length; i++) {
    if (i <= 1) continue; // 0 and 1 are not prime
    if (sieve[i] === true) {
      primes.push(i)
    }
  }

  return primes
}

module.exports = { sieve }
