%EDM Workshop2 
%Q1.5
%plot the vector field F of parts (b)
x=0:.5:2;
y=0:.5:2;
z=0:.5:2;
[xx,yy,zz]=meshgrid(x,y,z);
Fxx=xx;
Fyy=zeros(size(yy));
Fzz=zz;
figure(1);
quiver3(xx,yy,zz,Fxx,Fyy,Fzz);
%plot the vector field F of parts (c)
Fxxnew=zz;
Fyynew=zeros(size(yy));
Fzznew=-xx;
figure(2);
quiver3(xx,yy,zz,Fxxnew,Fyynew,Fzznew);
%Discuss the relationship between the computed
%divergence and curl with the vector field plots obtained
%Q2.1.7
x = 0:.2:1;
y = x; z = x;
[xx,yy,zz] = meshgrid(x,y,z);
Exx = yy; Eyy = xx; Ezz = 0*xx;
figure(3);
quiver3(xx,yy,zz,Exx,Eyy,Ezz);
xlabel('x'); ylabel('y'); zlabel('z');
grid on; hold on;
P1 = [1;0;0]; P2 = [0;1;0];
s = 0:.05:1;
L1 = P1*(1 - s) + P2*s;
L2 = P1*cos(pi*s/2) + P2*sin(pi*s/2);
plot3(L1(1,:),L1(2,:),L1(3,:),'g');
plot3(L2(1,:),L2(2,:),L2(3,:),'r');