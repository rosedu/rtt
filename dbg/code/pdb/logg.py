#!/usr/bin/env python

import logging
import optparse

LOGGING_LEVELS = {'critical': logging.CRITICAL,
        'error': logging.ERROR,
        'warning': logging.WARNING,
        'info': logging.INFO,
        'debug': logging.DEBUG}

def main():
    parser = optparse.OptionParser()
    parser.add_option('-l', '--loglevel', help='Logging level')
    parser.add_option('-f', '--logfile', help='Logging file name')
    (options, args) = parser.parse_args()
    logging_level = LOGGING_LEVELS.get(options.loglevel, logging.NOTSET)
    logging.basicConfig(level=logging_level, filename=options.logfile,
          format='%(asctime)s %(levelname)s: %(message)s',
          datefmt='%Y-%m-%d %H:%M:%S')

    # Your program goes here.
    # You can access command-line arguments using the args variable.
    logging.info('Program started.')
    logging.debug('Arguments are: %s' % str(args))
    logging.warning('About to close.')
    logging.error('Unhandled exception: code is about to terminate.')
    logging.critical('Exiting.')

if __name__ == '__main__':
    main()
