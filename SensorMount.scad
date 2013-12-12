difference(){
	cylinder(h = 30, r=70);
	translate([0,-70,0])cube(size = [70,140,70]);
	rotate([0,0,30])translate([-11.75,0,3])cube(size = [23.5,70,20.5]);
	rotate([0,0,70])translate([-11.75,0,3])cube(size = [23.5,70,20.5]);
	rotate([0,0,110])translate([-11.75,0,3])cube(size = [23.5,70,20.5]);
	rotate([0,0,150])translate([-11.75,0,3])cube(size = [23.5,70,20.5]);
}

