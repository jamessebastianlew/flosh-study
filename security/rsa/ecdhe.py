from random import randint


def pow_mod(base, pow, mod):
    if pow == 0:
        return 1
    if pow % 2 == 0:
        return pow_mod(base * base % mod, pow // 2, mod) % mod
    return pow_mod(base * base % mod, pow // 2, mod) * base % mod

def generate_public():
    return {'g': randint(1, 1000), 'n': randint(1, 1000)}

def generate_private():
    return randint(1, 1000)


class Public:
    def __init__(self):
        self.public_keys = generate_public()
        self.mixed_keys = {}

    def add_mixed(self, person):
        self.mixed_keys[person.id] = pow_mod(self.public_keys['g'], person.private_key, self.public_keys['n'])

id = 0
class Person:
    def __init__(self):
        self.private_key = generate_private()
        self.shared_key = None
        global id
        self.id = id
        id += 1

    def get_shared(self, public, person_b_id):
        self.shared_key = pow_mod(public.mixed_keys[person_b_id], self.private_key, public.public_keys['n'])


if __name__ == '__main__':
    public = Public()
    a = Person()
    b = Person()

    public.add_mixed(a)
    public.add_mixed(b)

    a.get_shared(public, b.id)
    b.get_shared(public, a.id)

    print(a.shared_key)
    print(b.shared_key)

    


