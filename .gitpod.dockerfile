FROM gitpod/workspace-full:latest

USER root
# to avoid keyboard-config while installing gnuplot
ENV DEBIAN_FRONTEND noninteractive 
# Install custom tools, runtime, etc.
RUN apt-get update && apt-get install -y \
        gnuplot\
    && apt-get clean && rm -rf /var/cache/apt/* && rm -rf /var/lib/apt/lists/* && rm -rf /tmp/*
