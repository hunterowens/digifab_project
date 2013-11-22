difference(){
	cylinder(h = 30, r=70);
	translate([0,-30,0])cube(size = [40,60,30]);
	rotate([0,0,0])translate([-11.75,0,3])cube(size = [23.5,35,20.5]);
	rotate([0,0,70])translate([-11.75,0,3])cube(size = [23.5,35,20.5]);
	rotate([0,0,110])translate([-11.75,0,3])cube(size = [23.5,35,20.5]);
	rotate([0,0,150])translate([-11.75,0,3])cube(size = [23.5,35,20.5]);
}
