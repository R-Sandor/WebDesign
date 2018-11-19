// PoVRay 3.7 Scene File "Tower_Round_0demo.pov"
// author: Friedrich A. Lohmueller, Jan-2006/Aug-2009/Jan-2011
// email: Friedrich.Lohmueller_at_t-online.de
// homepage: http://www.f-lohmueller.de
//--------------------------------------------------------------------------
#version 3.6; // 3.7;
global_settings{ assumed_gamma 1.0 }
#default{ finish{ ambient 0.1 diffuse 0.9 }} 
//--------------------------------------------------------------------------
#include "colors.inc"
#include "textures.inc"
#include "glass.inc"
#include "metals.inc"
#include "golds.inc"
#include "stones.inc"
#include "woods.inc"
#include "shapes.inc"
#include "shapes2.inc"
#include "functions.inc"
#include "math.inc"
#include "transforms.inc"
//--------------------------------------------------------------------------
// camera ------------------------------------------------------------------
//------------------------------------------------------------------------

// THis camera looks at the far out tower
#declare Camera_0 =camera {/*ultra_wide_angle*/ angle 100  // diagonal view     
                                      //X the location around the point of which the camera is looking
                                             //y up and down   // Z value in and out 
                            location <-0.00, 100,46.00>
                            right     x*image_width/image_height
                            look_at   < 60.00,5.00,60.00>}
/*
Birds eye view
*/
                            
#declare Camera_1 = camera {/*ultra_wide_angle*/ angle 100  // diagonal view     
                                      //X the location around the point of which the camera is looking
                                             //y up and down   // Z value in and out 
                            location <-0.00, 100,-7.00>
                            right     x*image_width/image_height
                            look_at   < 0.00,5.00, 85.00>}
#declare Camera_2 = camera {/*ultra_wide_angle*/ angle 60  //right side view
                            location  <-50.0 , 40.0 ,40.0>
                            right     x*image_width/image_height
                            look_at   <40.0 , 10.0 ,90.0>}
#declare Camera_3 = camera {/*ultra_wide_angle*/ angle 90        // top view
                            location  <0.0 , 3.0 ,-0.001>
                            right     x*image_width/image_height
                            look_at   <0.0 , 1.0 , 0.0>}
camera{Camera_2}
//------------------------------------------------------------------------
// sun -------< 1000,2500,-2500> ------------------------------------------------------------
light_source{<1000,000,-2500> color White}
// sky -------------------------------------------------------------------
plane{<0,1,0>,1 hollow  
       texture{ pigment{ bozo turbulence 0.92
                         color_map { [0.00 rgb <0.50, 0.50, .50>]
                                     [0.50 rgb <0.50, 0.50, .50>]
                                     [0.70 rgb <1,1,1>]
                                     [0.85 rgb <0.25,0.25,0.25>]
                                     [1.0 rgb <0.5,0.5,0.5>]}
                        scale<1,1,1.5>*2.5  translate< 0,0,0>
                       }
                finish {ambient .05 diffuse 25} }      
       scale 10000}
// fog on the ground -------------------------------------------------
fog { fog_type   2
      distance   55
      color      Grey  
      fog_offset 0.1
      fog_alt    15
      turbulence 5. 
      turb_depth .100
    }




















//---------------------------------------------------------------------------------------
//----------------------------------------------------------------------------- textures
#declare Brick_Scale     = <0.07, 0.075, 2>; 
#declare Brick_Translate = <0.0,-0.06+0.25,-0.90>;
#declare Brick_Intensity = 0.35; 
//------------------------------------------------------------- textures
#declare Tower_Texture_1 = // sandstone
         texture { pigment{ color rgb< 0.10, 0.10, 0.10>}
                   normal { pigment_pattern{ brick 
                                             
                                             color rgb 0.2, 
                                             color rgb 0.8    //mortar 0.10
                                             scale Brick_Scale 
                                             translate Brick_Translate
                                             rotate<0,0,0>} Brick_Intensity}
                   finish { phong 0.1}
                 } // end of texture 
#declare Tower_Texture_2 = // sandstone
         texture { pigment{ color rgb< 0.00, 0.00, 0.00>*0.95*1.2}
                            // color rgb< 0.4,1,0.0>} // test_color
                   normal { pigment_pattern{ brick 
                                             color rgb 0.2, 
                                             color rgb 0.8 
                                             scale Brick_Scale
                                             translate Brick_Translate
                                             rotate<0,0,0>} Brick_Intensity}
                   finish { phong 0.1}
                 } // end of texture   
                 
                 
                 
/*
   All of my towers 
*/
//---------------------------------------------------------------------------------------
#include "Tower_Round_0.inc" 
//---------------------------------------------------------------------------------------
object{ Tower_Round_0(   2.50, // Tower_R, // tower radius in x and z                                
                         8.00, // Tower_H, // tower heigth in y 
                         1.50, // Tower_Balustrade_H, // tower balustrade high
                         0.35, // Tower_Wall_D,       // tower wall deepth 
                         0.66, // Battlements_H,           // battlements height in y
                         15.5 // Battlements_Angle,   // battlements angle in xz around y 
                         Tower_Texture_1, // outside texture
                         Tower_Texture_2  // battlements tween texture
                       ) //------------------------------------------------------------// 
        scale <1,1,1>*1
        rotate<0, 0,0> 
        translate<-8.00,13, 62.00>
        }

//---------------------------------------------------------------------------------------
//-Secon tower--------------------------------------------------------------------------------------    
object{ Tower_Round_0(   2.50, // Tower_R, // tower radius in x and z                                
                         8.00, // Tower_H, // tower heigth in y 
                         1.50, // Tower_Balustrade_H, // tower balustrade high
                         0.35, // Tower_Wall_D,       // tower wall deepth 
                         0.66, // Battlements_H,           // battlements height in y
                         15.5 // Battlements_Angle,   // battlements angle in xz around y 
                         Tower_Texture_1, // outside texture
                         Tower_Texture_2  // battlements tween texture
                       ) //------------------------------------------------------------// 
        scale <1,1,1>*1
        rotate<0, 0,0> 
        translate<10.00,13.00, 50.00>
        }     
// Thrid tower away from focal point 
object{ Tower_Round_0(   2.50, // Tower_R, // tower radius in x and z                                
                         8.00, // Tower_H, // tower heigth in y 
                         1.50, // Tower_Balustrade_H, // tower balustrade high
                         0.35, // Tower_Wall_D,       // tower wall deepth 
                         0.66, // Battlements_H,           // battlements height in y
                         15.5 // Battlements_Angle,   // battlements angle in xz around y 
                         Tower_Texture_1, // outside texture
                         Tower_Texture_2  // battlements tween texture
                       ) //------------------------------------------------------------// 
        scale <1,1,1>*.75
        rotate<0, 0,0> 
        translate<100.00,16.50, 50.00>
        }   
// Tower on mound 
object{ Tower_Round_0(   2.50, // Tower_R, // tower radius in x and z                                
                         8.00, // Tower_H, // tower heigth in y 
                         1.50, // Tower_Balustrade_H, // tower balustrade high
                         0.35, // Tower_Wall_D,       // tower wall deepth 
                         0.66, // Battlements_H,           // battlements height in y
                         15.5 // Battlements_Angle,   // battlements angle in xz around y 
                         Tower_Texture_1, // outside texture
                         Tower_Texture_2  // battlements tween texture
                       ) //------------------------------------------------------------// 
        scale <1,1,1>*1
        rotate<0, 0,-5> 
        translate<17.5,10, 125>
        }     
          
        
        
                          
// ground ----------------------------------
// settings of squared plane dimensions
// -- stripes distance - Strichabstand:
#declare RasterScale = 1.0;
// -- stripes width    - Strichbreite
#declare RasterHalfLine  = 0.05;
// -- dito in z direction
#declare RasterHalfLineZ = 0.05;
// -- stripes color    - Stichfarbe
#declare Raster_Color = <1,1,1>*0.2;
//------------------------------------------
#macro Raster(RScale, HLine)
       pigment{
           gradient x scale RScale
           color_map{
            [0.000   color rgb Raster_Color]
            [0+HLine color rgb Raster_Color]
            [0+HLine color rgbt<1,1,1,1>]
            [1-HLine color rgbt<1,1,1,1>]
            [1-HLine color rgb Raster_Color]
            [1.000   color rgb Raster_Color]
            }// end of color_map
           }// end of pigment
 #end// end of Raster(RScale, HLine)-macro
//-------------------------------------------
       
                                  
         
// Snow control
#declare snow_density=1.0;
#declare snow_color=<0.95, 0.95, 1.0>;
#declare snow_height=0.5;
// Forest control
declare forest_color_density=1.0;
#declare forest_normal=1.0; 
#declare forest_normal_scale=1.0; 
// Bushes control
#declare bushes_color_density=1.0; 
#declare bushes_normal=1.0;
#declare bushes_normal_scale=1.0;
#declare UseGranite=0 ;              
#include "slope_patterns.inc"
#declare rock_color=<0.55,0.45,0.3> ;
#include "maprock1.inc"      
#declare strata = pigment {gradient y color_map{rock_map} warp {turbulence 0.1}}
         

#declare rock_color=<0.55,0.45,0.3>; // Mandatory
#include "maprock1.inc"

height_field{ png "mountianrange.png"         
              texture {slope_rock_bushes scale 1} 
                      
                
              translate<-0.5,-.1,0> scale<200,33,300>}
                            
                            
                            
#declare granite_density=1.5; // Optional. Declare only if you want a value different than 1.2 (ex. 1.5 for a lighter texture, 1.0 for a darker one).
#declare granite_ambient_finish = 0.0; // Optional. Increase to get smoother shadows. Default is 0.2.
#include "geomorph_txtr.inc"

   
height_field{ png "mountianrange.png" smooth        
              texture {slope_rock_bushes scale .1}
                  
              translate<0,-0.05,0> scale<1000,23,130>}
              // water ------------------------------
                                                                   
      plane{<0,.05,0>, 0
      texture{pigment{rgb <.0,0,1>}
              finish {ambient .45
                      diffuse 0
                      brilliance 1.5
                      phong 0.8
                      phong_size 15
                      reflection 0.0}
              }// end of texture
     }// end of plane
//------------------         

// Walls           


//---------------------------------------------------------------------------------------
//----------------------------------------------------------------------------- textures
#declare Brick_Scale     = < 0.064,0.065,0.140>; 
#declare Brick_Translate = < 0.00,-0.20,  0.30>*3;
#declare Brick_Intensity = 0.35; 
//------------------------------------------------------------- textures
#declare Wall_Texture_1 = // sand stone
         texture { pigment{ color rgb< 0.10, 0.10, 0.10>}
                   normal { pigment_pattern{ brick 
                                             color rgb 0.2, 
                                             color rgb 0.8 
                                             scale Brick_Scale 
                                             translate Brick_Translate
                                             rotate<0,0,0>} Brick_Intensity}
                   finish { diffuse 0.9 phong 0.1}
                 } // end of texture 
#declare Wall_Texture_2 = // sand stone
         texture { pigment{ color rgb< 0.90, 0.78, 0.60>*0.95}
                            // color rgb< 0.4,1,0.0>} // test_color
                   normal { pigment_pattern{ brick 
                                             color rgb 0.2, 
                                             color rgb 0.8 
                                             scale Brick_Scale
                                             translate Brick_Translate
                                             rotate<0,90,0>} Brick_Intensity}
                   finish { diffuse 0.9 phong 0.1}
                 } // end of texture 
#include "Battlements_0.inc" 
//-------------------------------------------------------------------------------------// 
object{ Battlements_0(   3.00, // Wall__W, // half wall width in x                                
                         8.50, // Wall__H, // wall heigth in y 
                         1.50, // Wall__D, // wall deepth in z 
                         1.55, // Balustrade_H, // balustrade high
                         0.40, // Battlement__Wall_D, // battlement wall deepth 
                         0.70, // Battlement__H,    // battlements height in y
                         0.20, // Battlement__R,  // half battlements width in x or z 
                         1.25, // Tween_Distance, // >2*Battlement__R;  tween distance  
                         Wall_Texture_1, // outside texture
                         Wall_Texture_2  // battlements tween texture
                       ) //------------------------------------------------------------// 
        scale <1,1,1>*1
        rotate<0,35,0> 
        translate<-3,12.00, 59>   }           
        
// wall to the right of the focal tower
object{ Battlements_0(   3.00, // Wall__W, // half wall width in x                                
                         8.50, // Wall__H, // wall heigth in y 
                         1.50, // Wall__D, // wall deepth in z 
                         1.55, // Balustrade_H, // balustrade high
                         0.40, // Battlement__Wall_D, // battlement wall deepth 
                         0.70, // Battlement__H,    // battlements height in y
                         0.20, // Battlement__R,  // half battlements width in x or z 
                         1.25, // Tween_Distance, // >2*Battlement__R;  tween distance  
                         Wall_Texture_1, // outside texture
                         Wall_Texture_2  // battlements tween texture
                       ) //------------------------------------------------------------// 
        scale <1,1,1>*1
        rotate<0,35,0> 
          translate<1.95,12.00, 55.57>  }  
                  
// second wall to the right of the focal tower
object{ Battlements_0(   3.00, // Wall__W, // half wall width in x                                
                         8.50, // Wall__H, // wall heigth in y 
                         1.50, // Wall__D, // wall deepth in z 
                         1.55, // Balustrade_H, // balustrade high
                         0.40, // Battlement__Wall_D, // battlement wall deepth 
                         0.70, // Battlement__H,    // battlements height in y
                         0.20, // Battlement__R,  // half battlements width in x or z 
                         1.25, // Tween_Distance, // >2*Battlement__R;  tween distance  
                         Wall_Texture_1, // outside texture
                         Wall_Texture_2  // battlements tween texture
                       ) //------------------------------------------------------------// 
        scale <1,1,1>*1
        rotate<0,35,0> 
          translate<5.75,12.00, 53>  }   
// third wall to the right of the focal tower
object{ Battlements_0(   3.00, // Wall__W, // half wall width in x                                
                         8.50, // Wall__H, // wall heigth in y 
                         1.50, // Wall__D, // wall deepth in z 
                         1.55, // Balustrade_H, // balustrade high
                         0.40, // Battlement__Wall_D, // battlement wall deepth 
                         0.70, // Battlement__H,    // battlements height in y
                         0.20, // Battlement__R,  // half battlements width in x or z 
                         1.25, // Tween_Distance, // >2*Battlement__R;  tween distance  
                         Wall_Texture_1, // outside texture
                         Wall_Texture_2  // battlements tween texture
                       ) //------------------------------------------------------------// 
        scale <1,1,1>*1
        rotate<0,0,0> 
          translate<15,12.00, 49>  }         
// fourth wall to the right of the focal tower
object{ Battlements_0(   3.00, // Wall__W, // half wall width in x                                
                         8.50, // Wall__H, // wall heigth in y 
                         1.50, // Wall__D, // wall deepth in z 
                         1.55, // Balustrade_H, // balustrade high
                         0.40, // Battlement__Wall_D, // battlement wall deepth 
                         0.70, // Battlement__H,    // battlements height in y
                         0.20, // Battlement__R,  // half battlements width in x or z 
                         1.25, // Tween_Distance, // >2*Battlement__R;  tween distance  
                         Wall_Texture_1, // outside texture
                         Wall_Texture_2  // battlements tween texture
                       ) //------------------------------------------------------------// 
        scale <1,1,1>*1
        rotate<0,0,0> 
          translate<20,12.00, 49>  }
// fifth wall to the right of the focal tower
object{ Battlements_0(   3.00, // Wall__W, // half wall width in x                                
                         8.50, // Wall__H, // wall heigth in y 
                         1.50, // Wall__D, // wall deepth in z 
                         1.55, // Balustrade_H, // balustrade high
                         0.40, // Battlement__Wall_D, // battlement wall deepth 
                         0.70, // Battlement__H,    // battlements height in y
                         0.20, // Battlement__R,  // half battlements width in x or z 
                         1.25, // Tween_Distance, // >2*Battlement__R;  tween distance  
                         Wall_Texture_1, // outside texture
                         Wall_Texture_2  // battlements tween texture
                       ) //------------------------------------------------------------// 
        scale <1,1,1>*1
        rotate<0,0,0> 
          translate<26,12.00, 49>  }  
// sixth wall from the focal tower   
object{ Battlements_0(   3.00, // Wall__W, // half wall width in x                                
                         8.50, // Wall__H, // wall heigth in y 
                         1.50, // Wall__D, // wall deepth in z 
                         1.55, // Balustrade_H, // balustrade high
                         0.40, // Battlement__Wall_D, // battlement wall deepth 
                         0.70, // Battlement__H,    // battlements height in y
                         0.20, // Battlement__R,  // half battlements width in x or z 
                         1.25, // Tween_Distance, // >2*Battlement__R;  tween distance  
                         Wall_Texture_1, // outside texture
                         Wall_Texture_2  // battlements tween texture
                       ) //------------------------------------------------------------// 
        scale <1,1,1>*1
        rotate<0,0,-9> 
          translate<31,11.70, 49>  }   
// seventh wall from the focal tower   
object{ Battlements_0(   3.00, // Wall__W, // half wall width in x                                
                         8.50, // Wall__H, // wall heigth in y 
                         1.50, // Wall__D, // wall deepth in z 
                         1.55, // Balustrade_H, // balustrade high
                         0.40, // Battlement__Wall_D, // battlement wall deepth 
                         0.70, // Battlement__H,    // battlements height in y
                         0.20, // Battlement__R,  // half battlements width in x or z 
                         1.25, // Tween_Distance, // >2*Battlement__R;  tween distance  
                         Wall_Texture_1, // outside texture
                         Wall_Texture_2  // battlements tween texture
                       ) //------------------------------------------------------------// 
        scale <1,1,1>*1
        rotate<0,0,-9> 
          translate<36,10.70, 49>  }   
          
// eight wall from the focal tower   
object{ Battlements_0(   3.00, // Wall__W, // half wall width in x                                
                         8.50, // Wall__H, // wall heigth in y 
                         1.50, // Wall__D, // wall deepth in z 
                         1.55, // Balustrade_H, // balustrade high
                         0.40, // Battlement__Wall_D, // battlement wall deepth 
                         0.70, // Battlement__H,    // battlements height in y
                         0.20, // Battlement__R,  // half battlements width in x or z 
                         1.25, // Tween_Distance, // >2*Battlement__R;  tween distance  
                         Wall_Texture_1, // outside texture
                         Wall_Texture_2  // battlements tween texture
                       ) //------------------------------------------------------------// 
        scale <1,1,1>*1
        rotate<0,0,-9> 
          translate<41,9.70, 49>  }   

          
// nineth wall from the focal tower   
object{ Battlements_0(   3.00, // Wall__W, // half wall width in x                                
                         8.50, // Wall__H, // wall heigth in y 
                         1.50, // Wall__D, // wall deepth in z 
                         1.55, // Balustrade_H, // balustrade high
                         0.40, // Battlement__Wall_D, // battlement wall deepth 
                         0.70, // Battlement__H,    // battlements height in y
                         0.20, // Battlement__R,  // half battlements width in x or z 
                         1.25, // Tween_Distance, // >2*Battlement__R;  tween distance  
                         Wall_Texture_1, // outside texture
                         Wall_Texture_2  // battlements tween texture
                       ) //------------------------------------------------------------// 
        scale <1,1,1>*1
        rotate<0,0,-9> 
          translate<46,8.70, 49>  }                             
       
          
// tenth wall from the focal tower   
object{ Battlements_0(   3.00, // Wall__W, // half wall width in x                                
                         8.50, // Wall__H, // wall heigth in y 
                         1.50, // Wall__D, // wall deepth in z 
                         1.55, // Balustrade_H, // balustrade high
                         0.40, // Battlement__Wall_D, // battlement wall deepth 
                         0.70, // Battlement__H,    // battlements height in y
                         0.20, // Battlement__R,  // half battlements width in x or z 
                         1.25, // Tween_Distance, // >2*Battlement__R;  tween distance  
                         Wall_Texture_1, // outside texture
                         Wall_Texture_2  // battlements tween texture
                       ) //------------------------------------------------------------// 
        scale <1,1,1>*1
        rotate<0,0,-9> 
          translate<51,7.70, 49>  }                           
      
          
// Eleventh wall from the focal tower   
object{ Battlements_0(   3.00, // Wall__W, // half wall width in x                                
                         8.50, // Wall__H, // wall heigth in y 
                         1.50, // Wall__D, // wall deepth in z 
                         1.55, // Balustrade_H, // balustrade high
                         0.40, // Battlement__Wall_D, // battlement wall deepth 
                         0.70, // Battlement__H,    // battlements height in y
                         0.20, // Battlement__R,  // half battlements width in x or z 
                         1.25, // Tween_Distance, // >2*Battlement__R;  tween distance  
                         Wall_Texture_1, // outside texture
                         Wall_Texture_2  // battlements tween texture
                       ) //------------------------------------------------------------// 
        scale <1,1,1>*1
        rotate<0,0,-9> 
          translate<56,6.70, 49>  }   
          
// Twevelth wall from the focal tower   
object{ Battlements_0(   3.00, // Wall__W, // half wall width in x                                
                         8.50, // Wall__H, // wall heigth in y 
                         1.50, // Wall__D, // wall deepth in z 
                         1.55, // Balustrade_H, // balustrade high
                         0.40, // Battlement__Wall_D, // battlement wall deepth 
                         0.70, // Battlement__H,    // battlements height in y
                         0.20, // Battlement__R,  // half battlements width in x or z 
                         1.25, // Tween_Distance, // >2*Battlement__R;  tween distance  
                         Wall_Texture_1, // outside texture
                         Wall_Texture_2  // battlements tween texture
                       ) //------------------------------------------------------------// 
        scale <1,1,1>*1
        rotate<0,0,0> 
          translate<61,5.70, 49>  }     
                                 
           
// 13th wall from the focal tower   
object{ Battlements_0(   3.00, // Wall__W, // half wall width in x                                
                         8.50, // Wall__H, // wall heigth in y 
                         1.50, // Wall__D, // wall deepth in z 
                         1.55, // Balustrade_H, // balustrade high
                         0.40, // Battlement__Wall_D, // battlement wall deepth 
                         0.70, // Battlement__H,    // battlements height in y
                         0.20, // Battlement__R,  // half battlements width in x or z 
                         1.25, // Tween_Distance, // >2*Battlement__R;  tween distance  
                         Wall_Texture_1, // outside texture
                         Wall_Texture_2  // battlements tween texture
                       ) //------------------------------------------------------------// 
        scale <1,1,1>*1
        rotate<0,0,9> 
          translate<66,6.70, 49>  }
            
// 14th wall from the focal tower   
object{ Battlements_0(   3.00, // Wall__W, // half wall width in x                                
                         8.50, // Wall__H, // wall heigth in y 
                         1.50, // Wall__D, // wall deepth in z 
                         1.55, // Balustrade_H, // balustrade high
                         0.40, // Battlement__Wall_D, // battlement wall deepth 
                         0.70, // Battlement__H,    // battlements height in y
                         0.20, // Battlement__R,  // half battlements width in x or z 
                         1.25, // Tween_Distance, // >2*Battlement__R;  tween distance  
                         Wall_Texture_1, // outside texture
                         Wall_Texture_2  // battlements tween texture
                       ) //------------------------------------------------------------// 
        scale <1,1,1>*1
        rotate<0,0,9> 
          translate<71,7.70, 49>  }     

// 15th wall from the focal tower   
object{ Battlements_0(   3.00, // Wall__W, // half wall width in x                                
                         8.50, // Wall__H, // wall heigth in y 
                         1.50, // Wall__D, // wall deepth in z 
                         1.55, // Balustrade_H, // balustrade high
                         0.40, // Battlement__Wall_D, // battlement wall deepth 
                         0.70, // Battlement__H,    // battlements height in y
                         0.20, // Battlement__R,  // half battlements width in x or z 
                         1.25, // Tween_Distance, // >2*Battlement__R;  tween distance  
                         Wall_Texture_1, // outside texture
                         Wall_Texture_2  // battlements tween texture
                       ) //------------------------------------------------------------// 
        scale <1,1,1>*1
        rotate<0,0,9> 
          translate<76,8.70, 49>  } 
          
// 17th wall from the focal tower   
object{ Battlements_0(   3.00, // Wall__W, // half wall width in x                                
                         8.50, // Wall__H, // wall heigth in y 
                         1.50, // Wall__D, // wall deepth in z 
                         1.55, // Balustrade_H, // balustrade high
                         0.40, // Battlement__Wall_D, // battlement wall deepth 
                         0.70, // Battlement__H,    // battlements height in y
                         0.20, // Battlement__R,  // half battlements width in x or z 
                         1.25, // Tween_Distance, // >2*Battlement__R;  tween distance  
                         Wall_Texture_1, // outside texture
                         Wall_Texture_2  // battlements tween texture
                       ) //------------------------------------------------------------// 
        scale <1,1,1>*1
        rotate<0,0,9> 
          translate<81,9.70, 49>  }
                    
// 18th wall from the focal tower   
object{ Battlements_0(   3.00, // Wall__W, // half wall width in x                                
                         8.50, // Wall__H, // wall heigth in y 
                         1.50, // Wall__D, // wall deepth in z 
                         1.55, // Balustrade_H, // balustrade high
                         0.40, // Battlement__Wall_D, // battlement wall deepth 
                         0.70, // Battlement__H,    // battlements height in y
                         0.20, // Battlement__R,  // half battlements width in x or z 
                         1.25, // Tween_Distance, // >2*Battlement__R;  tween distance  
                         Wall_Texture_1, // outside texture
                         Wall_Texture_2  // battlements tween texture
                       ) //------------------------------------------------------------// 
        scale <1,1,1>*1
        rotate<0,0,9> 
          translate<86,10.70, 49>  }  

// 19th wall from the focal tower   
object{ Battlements_0(   3.00, // Wall__W, // half wall width in x                                
                         8.50, // Wall__H, // wall heigth in y 
                         1.50, // Wall__D, // wall deepth in z 
                         1.55, // Balustrade_H, // balustrade high
                         0.40, // Battlement__Wall_D, // battlement wall deepth 
                         0.70, // Battlement__H,    // battlements height in y
                         0.20, // Battlement__R,  // half battlements width in x or z 
                         1.25, // Tween_Distance, // >2*Battlement__R;  tween distance  
                         Wall_Texture_1, // outside texture
                         Wall_Texture_2  // battlements tween texture
                       ) //------------------------------------------------------------// 
        scale <1,1,1>*1
        rotate<0,0,9> 
          translate<91,11.70, 49>  } 

// 20th wall from the focal tower   
object{ Battlements_0(   3.00, // Wall__W, // half wall width in x                                
                         8.50, // Wall__H, // wall heigth in y 
                         1.50, // Wall__D, // wall deepth in z 
                         1.55, // Balustrade_H, // balustrade high
                         0.40, // Battlement__Wall_D, // battlement wall deepth 
                         0.70, // Battlement__H,    // battlements height in y
                         0.20, // Battlement__R,  // half battlements width in x or z 
                         1.25, // Tween_Distance, // >2*Battlement__R;  tween distance  
                         Wall_Texture_1, // outside texture
                         Wall_Texture_2  // battlements tween texture
                       ) //------------------------------------------------------------// 
        scale <1,1,1>*1
        rotate<0,0,9> 
          translate<96,12.70, 49>  }                
                          

// 21st wall from the focal tower   
object{ Battlements_0(   3.00, // Wall__W, // half wall width in x                                
                         8.50, // Wall__H, // wall heigth in y 
                         1.50, // Wall__D, // wall deepth in z 
                         1.55, // Balustrade_H, // balustrade high
                         0.40, // Battlement__Wall_D, // battlement wall deepth 
                         0.70, // Battlement__H,    // battlements height in y
                         0.20, // Battlement__R,  // half battlements width in x or z 
                         1.25, // Tween_Distance, // >2*Battlement__R;  tween distance  
                         Wall_Texture_1, // outside texture
                         Wall_Texture_2  // battlements tween texture
                       ) //------------------------------------------------------------// 
        scale <1,1.25,1>*.75
        rotate<0,90,0>           
        translate<101,15.25, 47>  } 

// 21st wall from the focal tower   
object{ Battlements_0(   3.00, // Wall__W, // half wall width in x                                
                         8.50, // Wall__H, // wall heigth in y 
                         1.50, // Wall__D, // wall deepth in z 
                         1.55, // Balustrade_H, // balustrade high
                         0.40, // Battlement__Wall_D, // battlement wall deepth 
                         0.70, // Battlement__H,    // battlements height in y
                         0.20, // Battlement__R,  // half battlements width in x or z 
                         1.25, // Tween_Distance, // >2*Battlement__R;  tween distance  
                         Wall_Texture_1, // outside texture
                         Wall_Texture_2  // battlements tween texture
                       ) //------------------------------------------------------------// 
        scale <1,1.25,1>*.75
        rotate<0,90,0>           
        translate<101,15.25, 46>  }  
 

 
// 21st wall from the focal tower   
object{ Battlements_0(   3.00, // Wall__W, // half wall width in x                                
                         14.50, // Wall__H, // wall heigth in y 
                         1.50, // Wall__D, // wall deepth in z 
                         1.55, // Balustrade_H, // balustrade high
                         0.40, // Battlement__Wall_D, // battlement wall deepth 
                         0.70, // Battlement__H,    // battlements height in y
                         0.20, // Battlement__R,  // half battlements width in x or z 
                         1.25, // Tween_Distance, // >2*Battlement__R;  tween distance  
                         Wall_Texture_1, // outside texture
                         Wall_Texture_2  // battlements tween texture
                       ) //------------------------------------------------------------// 
        scale <1,1,1>*.75
        rotate<0,90,0>           
        translate<101,12.25, 44>  }  
                                     
// 21st wall from the focal tower   
object{ Battlements_0(   3.00, // Wall__W, // half wall width in x                                
                         14.50, // Wall__H, // wall heigth in y 
                         1.50, // Wall__D, // wall deepth in z 
                         1.55, // Balustrade_H, // balustrade high
                         0.40, // Battlement__Wall_D, // battlement wall deepth 
                         0.70, // Battlement__H,    // battlements height in y
                         0.20, // Battlement__R,  // half battlements width in x or z 
                         1.25, // Tween_Distance, // >2*Battlement__R;  tween distance  
                         Wall_Texture_1, // outside texture
                         Wall_Texture_2  // battlements tween texture
                       ) //------------------------------------------------------------// 
        scale <1,1,1>*.75
        rotate<0,90,0>           
        translate<101,12.25, 41>  }  
                                     
  
// 21st wall from the focal tower   
object{ Battlements_0(   3.00, // Wall__W, // half wall width in x                                
                         18.50, // Wall__H, // wall heigth in y 
                         1.50, // Wall__D, // wall deepth in z 
                         1.55, // Balustrade_H, // balustrade high
                         0.40, // Battlement__Wall_D, // battlement wall deepth 
                         0.70, // Battlement__H,    // battlements height in y
                         0.20, // Battlement__R,  // half battlements width in x or z 
                         1.25, // Tween_Distance, // >2*Battlement__R;  tween distance  
                         Wall_Texture_1, // outside texture
                         Wall_Texture_2  // battlements tween texture
                       ) //------------------------------------------------------------// 
        scale <1,1,1>*.75
        rotate<0,90,0>           
        translate<101,9.25, 39>  }  
 
// 21st wall from the focal tower   
object{ Battlements_0(   3.00, // Wall__W, // half wall width in x                                
                         17.50, // Wall__H, // wall heigth in y 
                         1.50, // Wall__D, // wall deepth in z 
                         1.55, // Balustrade_H, // balustrade high
                         0.40, // Battlement__Wall_D, // battlement wall deepth 
                         0.70, // Battlement__H,    // battlements height in y
                         0.20, // Battlement__R,  // half battlements width in x or z 
                         1.25, // Tween_Distance, // >2*Battlement__R;  tween distance  
                         Wall_Texture_1, // outside texture
                         Wall_Texture_2  // battlements tween texture
                       ) //------------------------------------------------------------// 
        scale <1,1,1>*.75
        rotate<0,90,0>           
        translate<101,7.5, 36>  }  
                                       
  
  
              
// wall to the left of the tower in focal on the far-left-front(T1)         
object{ Battlements_0(   3.00, // Wall__W, // half wall width in x                                
                         8.50, // Wall__H, // wall heigth in y 
                         1.50, // Wall__D, // wall deepth in z 
                         1.55, // Balustrade_H, // balustrade high
                         0.40, // Battlement__Wall_D, // battlement wall deepth 
                         0.70, // Battlement__H,    // battlements height in y
                         0.20, // Battlement__R,  // half battlements width in x or z 
                         1.25, // Tween_Distance, // >2*Battlement__R;  tween distance  
                         Wall_Texture_1, // outside texture
                         Wall_Texture_2  // battlements tween texture
                       ) //------------------------------------------------------------// 
scale <1,1,1>*1
rotate<0,20,0> 
translate<-13.50,12.00, 64>   }   


// Second wall segment attaching to the left of the tower. Part two 
object{ Battlements_0(   3.00, // Wall__W, // half wall width in x                                
                         8.50, // Wall__H, // wall heigth in y 
                         1.50, // Wall__D, // wall deepth in z 
                         1.55, // Balustrade_H, // balustrade high
                         0.40, // Battlement__Wall_D, // battlement wall deepth 
                         0.70, // Battlement__H,    // battlements height in y
                         0.20, // Battlement__R,  // half battlements width in x or z 
                         1.25, // Tween_Distance, // >2*Battlement__R;  tween distance  
                         Wall_Texture_1, // outside texture
                         Wall_Texture_2  // battlements tween texture
                       ) //------------------------------------------------------------// 
scale <1,1,1>*1
rotate<0,50,0> 
translate<-18.19,12.00, 67.25>   } 

// Thrid wall segment attaching to the left of the tower. Part three  
object{ Battlements_0(   3.00, // Wall__W, // half wall width in x                                
                         8.50, // Wall__H, // wall heigth in y 
                         1.50, // Wall__D, // wall deepth in z 
                         1.55, // Balustrade_H, // balustrade high
                         0.40, // Battlement__Wall_D, // battlement wall deepth 
                         0.70, // Battlement__H,    // battlements height in y
                         0.20, // Battlement__R,  // half battlements width in x or z 
                         1.25, // Tween_Distance, // >2*Battlement__R;  tween distance  
                         Wall_Texture_1, // outside texture
                         Wall_Texture_2  // battlements tween texture
                       ) //------------------------------------------------------------// 
scale <1,1,1>*1
rotate<0,50,0> 
translate<-21.7,12.00, 71.35>   }

// fourth wall segment attaching to the left of the tower. Part four  
object{ Battlements_0(   3.00, // Wall__W, // half wall width in x                                
                         8.50, // Wall__H, // wall heigth in y 
                         1.50, // Wall__D, // wall deepth in z 
                         1.55, // Balustrade_H, // balustrade high
                         0.40, // Battlement__Wall_D, // battlement wall deepth 
                         0.70, // Battlement__H,    // battlements height in y
                         0.20, // Battlement__R,  // half battlements width in x or z 
                         1.25, // Tween_Distance, // >2*Battlement__R;  tween distance  
                         Wall_Texture_1, // outside texture
                         Wall_Texture_2  // battlements tween texture
                       ) //------------------------------------------------------------// 
scale <1,1,1>*1
rotate<0,50,0> 
translate<-25.5,12.00, 75.85>   }    


// fifth wall segment attaching to the left of the tower. Part four  
object{ Battlements_0(   3.00, // Wall__W, // half wall width in x                                
                         8.50, // Wall__H, // wall heigth in y 
                         1.50, // Wall__D, // wall deepth in z 
                         1.55, // Balustrade_H, // balustrade high
                         0.40, // Battlement__Wall_D, // battlement wall deepth 
                         0.70, // Battlement__H,    // battlements height in y
                         0.20, // Battlement__R,  // half battlements width in x or z 
                         1.25, // Tween_Distance, // >2*Battlement__R;  tween distance  
                         Wall_Texture_1, // outside texture
                         Wall_Texture_2  // battlements tween texture
                       ) //------------------------------------------------------------// 
scale <1,1,1>*1
rotate<0,50,0> 
translate<-28.69,12.00, 79.65>   }        

#include "torch.inc"
// -------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------
object{ torch( 0.3,  // Shining_On, 0= off, >0 = intensity of candle light 
                  0, // Flame_Shadow, // >0 = intensity ; 0 = off
                  1.5,  // Candle_Height, relative to diameter (d=1) 
                  1.2,  // Candle_Intensity,  
                  0.7   // Candle_Flame_Scale
                  4, // Fade_Distance, //  3 ~ 5    
                  3 // Fade_Power //   2,3,4
                 ) // -------------------------
        scale 1
        rotate<0,0,0>
        translate<-8.00,20, 62.00>
      } // ------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------     



 //---------------------------------------------------------------------------------------
object{ torch( 0.3,  // Shining_On, 0= off, >0 = intensity of candle light 
                  0, // Flame_Shadow, // >0 = intensity ; 0 = off
                  1.5,  // Candle_Height, relative to diameter (d=1) 
                  1.2,  // Candle_Intensity,  
                  0.7   // Candle_Flame_Scale
                  5, // Fade_Distance, //  3 ~ 5    
                  300 // Fade_Power //   2,3,4
                 ) // -------------------------
        scale 1
        rotate<0,0,0>
         translate<10.00,20.00, 50.00>
      } // ------------------------------
object{ torch( 0.3,  // Shining_On, 0= off, >0 = intensity of candle light 
                  0, // Flame_Shadow, // >0 = intensity ; 0 = off
                  1.5,  // Candle_Height, relative to diameter (d=1) 
                  3.5,  // Candle_Intensity,  
                  0.7   // Candle_Flame_Scale
                  5, // Fade_Distance, //  3 ~ 5    
                  2 // Fade_Power //   2,3,4
                 ) // -------------------------
        scale 1
        rotate<0,0,0>
         translate<17.5,17, 123>
      } // ------------------------------   
      
object{ torch( 0.3,  // Shining_On, 0= off, >0 = intensity of candle light 
                  0, // Flame_Shadow, // >0 = intensity ; 0 = off
                  1.5,  // Candle_Height, relative to diameter (d=1) 
                  3.5,  // Candle_Intensity,  
                  0.7   // Candle_Flame_Scale
                  4, // Fade_Distance, //  3 ~ 5    
                  2 // Fade_Power //   2,3,4
                 ) // -------------------------
        scale 1
        rotate<0,0,0>
         translate<17.5,17, 125>
      } // ------------------------------

object{ torch( 0.3,  // Shining_On, 0= off, >0 = intensity of candle light 
                  0, // Flame_Shadow, // >0 = intensity ; 0 = off
                  1.5,  // Candle_Height, relative to diameter (d=1) 
                  3.5,  // Candle_Intensity,  
                  0.7   // Candle_Flame_Scale
                  5, // Fade_Distance, //  3 ~ 5    
                  2 // Fade_Power //   2,3,4
                 ) // -------------------------
        scale 1
        rotate<0,0,0>
         translate<17.5,17, 124>
      } // ------------------------------

  
   object{ torch( 0.3,  // Shining_On, 0= off, >0 = intensity of candle light 
                  0, // Flame_Shadow, // >0 = intensity ; 0 = off
                  1.5,  // Candle_Height, relative to diameter (d=1) 
                  3.5,  // Candle_Intensity,  
                  0.7   // Candle_Flame_Scale
                  5, // Fade_Distance, //  3 ~ 5    
                  2 // Fade_Power //   2,3,4
                 ) // -------------------------
        scale 1
        rotate<0,0,0>
          translate<100.00,21.50, 50.00>
      } // ------------------------------



                              










