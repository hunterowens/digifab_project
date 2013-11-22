difference(){
	cylinder(h = 10, r=20);
	translate([0,-20,0])cube(size = [20,40,20]);
	rotate([0,0,30])translate([0,15,2.5])cube(size = [5,5,5]);
	rotate([0,0,70])translate([0,15,2.5])cube(size = [5,5,5]);
	rotate([0,0,110])translate([0,15,2.5])cube(size = [5,5,5]);
	rotate([0,0,150])translate([0,15,2.5])cube(size = [5,5,5]);
}

