import os

from setuptools import setup, Extension

requires = []
ext_kwargs = {}


def read(file_name):
    return open(os.path.join(os.path.dirname(__file__), file_name), encoding='utf-8').read()


setup(
    # Basic package information:
    name='ref',
    version='0.0.1',

    # Packaging options:
    zip_safe=False,
    include_package_data=True,

    classifiers=[
        'Intended Audience :: Developers',
        'License :: OSI Approved :: BSD License',
        'Programming Language :: Python',
        'Programming Language :: Python :: 3',
    ],

    ext_modules=[
        Extension(
            'ref',
            ['src/counter.c'],
            **ext_kwargs
        )
    ],
)