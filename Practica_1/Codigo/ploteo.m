arbol_t = 'Textos/salida_6.txt';
shell_t = 'Textos/salida_5.txt';
seleccion_t = 'Textos/salida_4.txt';
insersion_t = 'Textos/salida_3.txt';
burbujaO_t = 'Textos/salida_2.txt';
burbuja_t= 'Textos/salida_6.txt';

datos_entrada = [100, 1000, 5000, 10000, 50000, 100000,200000, 400000, 600000, 800000];

arbol = importdata(arbol_t);

var1=arbol(:,1)'*100;
var2=arbol(:,2)'*100;
var3=arbol(:,3)'*1000000;

n=2;
p=polyfit(datos_entrada,var3,n)

xi=linspace(0.72,1.45,1000);
z=polyval(p,xi);

figure(1);
plot(datos_entrada,var1,'xg',xi,z,'-'),grid;
hold on;
plot(datos_entrada,var2,'ob'),grid;
hold on;
plot(datos_entrada,var3,'*r'),grid;
hold on;
ylabel('F(Y)');
xlabel('X');
title('Ajuste de minimos cuadrados');

