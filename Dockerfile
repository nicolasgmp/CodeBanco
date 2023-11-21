FROM gcc:latest
WORKDIR $PWD
COPY ContaBancaria.c ./
COPY ContaBancaria.h ./
COPY main.c ./
RUN gcc ContaBancaria.c main.c -o ContaBancaria -lm
CMD ["./ContaBancaria"]