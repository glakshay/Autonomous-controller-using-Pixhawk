position=[48392,-120012;
48402,-120012;
48392,-120212;
48402,-120212;]
latitutde=48395;
longitude=-120112;
x=4
yaw=271
 vector_a_y=(position(x,1)-latitutde);
vector_a_x=(position(x,2)-longitude);
thera_new1=atand(vector_a_x/vector_a_y);
dif_thera=(thera_new2-yaw)
if(position(x,1)>=latitutde && position(x,2) >= longitude)
    thera_new2=abs(thera_new1)
    q=1
elseif(position(x,1)<=latitutde && position(x,2) >= longitude)
    thera_new2=90+(thera_new1+90)
    q=2
    elseif(position(x,1)<=latitutde && position(x,2) <= longitude)
        thera_new2=180+thera_new1
       q=3 
else
    thera_new2=270+(thera_new1+90)
    q=4
end
if(yaw <=90 && yaw>0 )
    q1=1
elseif(yaw <=180 && yaw>90)
    q1=2
elseif(yaw<=270 && yaw>180)
    q1=3
else
    q1=4
end
if(q==4 && q1==1)
    y=-1
elseif(q==4 && q1==2)
    y=-1
elseif(q==4 && q1==3)
    y=1
    %
elseif(q==3 && q1==4)
    y=-1
elseif(q==3 && q1==1)
    y=-1
elseif(q==3 && q1==2)
    y=1
    %
elseif(q==2 && q1==4)
    y=-1
elseif(q==2 && q1==1)
    y=1
elseif(q==2 && q1==3)
    y=-1
     %
elseif(q==1 && q1==4)
    y=1
elseif(q==1 && q1==2)
    y=-1
elseif(q==1 && q1==3)
    y=-1
elseif(q==q1 && dif_thera <89 && dif_thera>=79)
    y=0.9
elseif(q==q1 && dif_thera <79 && dif_thera>=69)
    y=0.8
elseif(q==q1 && dif_thera <69 && dif_thera>=59)
    y=0.7
elseif(q==q1 && dif_thera <59 && dif_thera>=49)
    y=0.6
elseif(q==q1 && dif_thera <49 && dif_thera>=39)
    y=0.5
elseif(q==q1 && dif_thera <39 && dif_thera>=29)
    y=0.4
elseif(q==q1 && dif_thera <29 && dif_thera>=19)
    y=0.3
elseif(q==q1 && dif_thera <19 && dif_thera>=9)
    y=0.2
elseif(q==q1 && dif_thera <9 )
    y=0
    %
elseif(q==q1 && dif_thera <-89 && dif_thera>=-79)
    y=-0.9
elseif(q==q1 && dif_thera <-79 && dif_thera>=-69)
    y=-0.8
elseif(q==q1 && dif_thera <-69 && dif_thera>=-59)
    y=-0.7
elseif(q==q1 && dif_thera <-59 && dif_thera>=-49)
    y=-0.6
elseif(q==q1 && dif_thera <-49 && dif_thera>=-39)
    y=-0.5
elseif(q==q1 && dif_thera <-39 && dif_thera>=-29)
    y=-0.4
elseif(q==q1 && dif_thera <-29 && dif_thera>=-19)
    y=-0.3
elseif(q==q1 && dif_thera <-19 && dif_thera>=-9)
    y=-0.2
elseif(q==q1 && dif_thera <-9 )
    y=-0
end
%%-1=  Counterclockwise -1=  Clockwise
dif_thera=(thera_new2-yaw)
dif_thera1=(yaw-thera_new2)