#!/usr/bin/env python

def main():
    low, high = 0, 1
    for i in xrange(10):
        print high
        if high > 10:
            import code; code.interact(local=locals())
        low, high = high, low + high
 
if __name__ == '__main__':
    main()
