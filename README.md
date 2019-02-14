# xMsg

xMsg is a lightweight, yet full featured publish/subscribe messaging system,
presenting asynchronous inter-process communication.

## Overview

xMsg actors are required to publish and/or subscribe to messages.
The messages are identified by topics, and contain metadata
and user-serialized data.
xMsg topic convention defines three parts:
_domain_, _subject_, and _type_.
The data is identified by the _mime-type_ metadata field,
which can be used by applications to deserialize the raw bytes
into its proper data-type object.

Multi-threaded publication of messages is supported,
with each thread using its own connection to send messages.
Subscriptions run in a background thread,
and each received message is processed by a user-defined callback
executed by a thread-pool.
Note that the provided callback must be thread-safe.

A proxy must be running in order to pass messages between actors.
Messages must be published to the same proxy than the subscription,
or the subscriber will not receive them.
Long-lived actors can register with a global registrar service
if they are periodically publishing or subscribed to a given topic,
and others actors can search the registrar to discover them.


## Build notes

xMsg requires a C++14 compiler (GCC 4.9+) and CMake 3.1+

#### Ubuntu 14.04

Support PPAs:

    sudo apt-get install software-properties-common

Add a PPA for GCC (do not use GCC 5.x due to ABI changes):

    sudo add-apt-repository ppa:ubuntu-toolchain-r/test
    sudo apt-get update
    sudo apt-get install build-essential gcc-4.9 g++-4.9

Set GCC 4.9 as default:

    sudo update-alternatives \
            --install /usr/bin/gcc gcc /usr/bin/gcc-4.9 60 \
            --slave /usr/bin/g++ g++ /usr/bin/g++-4.9

Add a PPA for CMake:

    sudo add-apt-repository ppa:george-edison55/cmake-3.x
    sudo apt-get update
    sudo apt-get install cmake

#### Ubuntu 16.04

Install GCC and CMake from the repositories:

    sudo apt-get install build-essential cmake

#### Mac OS X 10.9 and newer

Install Xcode command line tools:

    xcode-select --install

Install CMake using [Homebrew](http://brew.sh/):

    brew install cmake

### Dependencies

xMsg uses [Protocol Buffers](https://developers.google.com/protocol-buffers/docs/downloads)
and [ZeroMQ](http://zeromq.org/area:download).

#### Ubuntu 14.04 and 16.04

Install from the repositories:

    sudo apt-get install libzmq3-dev libprotobuf-dev protobuf-compiler

#### Mac OS X 10.9 and newer

Use Homebrew:

    brew update
    brew install zeromq protobuf

### Installation

To build with CMake a configure wrapper script is provided:

    ./configure --prefix=<INSTALL_DIR>
    make
    make install


## Authors

For assistance contact authors:

* Vardan Gyurjyan    (<gurjyan@jlab.org>)
* Sebastián Mancilla (<smancill@jlab.org>)
* Ricardo Oyarzún    (<oyarzun@jlab.org>)

Enjoy...
