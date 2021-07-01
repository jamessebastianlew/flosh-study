"""

The general idea of RSA is for the receiver to generate a public and private key. The public key is sent to to sender to encrypt the message and the message is sent to the receiver who can the decrypt it with the private key.

Public Key: integers `n` and `e`.
Private Key: integer `d`.
Message: integer (or string) `m`

Generating the public and private key:

    we want `n`, `e`, `d` such that any `x` provides
    x ** (e * d) === x (mod n)

    so find two primes `p` and `q` then calculate:
        n = p * q
    and following this pick e, d:
        e * d === 1 (mod eulers_totient(n))
        -> i.e. e * d === 1 + k * eulers_totient(n)

        a. pick e === 1 (mod eulers_totient(n))
        b. then to get e * d === 1 (mod eulers_totient(n))
           pick d = inverse(e) using the extended euclidean
           algorithm

        now we have everything we need, we can send `n` and `e`
        (the public key) at will.

Generating the encrypted message:

    first let `m` be an integer representing our encrypted message.

    calculate c = m ** e mod n and send c (the encrypted message)
    to the receiver.

Decrypting the encrypted message:
    
    simply m = c ** d mod n


"""


from random import randint
### HELPER FUNCTIONS ###

def pow_mod(base, pow, mod):
    """ returns base ** pow % mod """
    if pow == 0:
        return 1
    if pow % 2 == 0:
        return pow_mod(base * base % mod, pow // 2, mod) % mod
    return pow_mod(base * base % mod, pow // 2, mod) * base % mod

def totient(p, q):
    """ returns totient of product of primes p, q (p * q) """
    return (p-1) * (q-1)

def ext_euclid(x, y):
    """ return (s, t) s.t. s * x - t * y = gcd(x, y) """
    if y % (x % y) == 0:
        return (1, -(x // y))
    (s, t) = ext_euclid(y, x % y)
    return (t, s - (x // y) * t)

def mod_inv(x, n):
    """ returns `d` s.t. x * d === 1 mod n """
    return ext_euclid(x, n)[0]

def get_primes():
    return (53, 59)

### RSA ###

def generate_keys():
    """ returns (n, e, d) """
    p, q = get_primes()
    n = p * q
    eulers_t = totient(p, q)
    k = randint(1, 10)
    e = (k * eulers_t + randint(1, eulers_t // 2) * 2 + 1) % eulers_t
    d = mod_inv(e, eulers_t) % eulers_t # e * (d + phin) == 1 mod phin)
    return {'n': n, 'e': e, 'd': d}


def encrypt_with_keys(m, n, e):
    return pow_mod(m, e, n)

def decrypt_with_private(c, d, n):
    return pow_mod(c, d, n)


if __name__ == '__main__':
    keys = generate_keys()
    m = 123
    print(keys)
    e_message = encrypt_with_keys(m, keys['n'], keys['e'])
    print(e_message)
    d_message = decrypt_with_private(e_message, keys['d'], keys['n'])
    print(d_message)


