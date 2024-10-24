#pragma once

#include <iostream>
#include <sstream>

static const char *LOGO = R"(
                                     X&+x+xxx$;             
                                $&+x;;&&$XXX&&::&           
            &+&.            :&++++&XXx;:   .:;x&;$.         
           $++xx++&&&&&&$+x++;++&$+.     Xx&&+$+$++         
           x&&+;;;;::;;;:$&&$$;+&.      .$XX+&&&+&;         
            :;+xxXXXXXXxx++:.+++X        X$x;;;&x;          
                             ;x+x         .;+++:            
                             ;+X+                           
                          :X$++X&:                          
                   +Xx;$x+xx$&$X++;.&&&$;                   
               $x++++++++;+$&$$$$+++++++++$$&x              
            $+++++:+xx.+++++++++++++;+$;+++x++x$&           
         .$X.&+++++++;+++;+++++x+++++++x++++x;++&&&         
        $$X++$++++;+++++x++++++X++++:+++++;;+x:++$&$:       
      $+;:+&++;+:+xx$$++++++++++;++++&.:$$++:$$$&&;+$:      
    .+X+++++++++$$;+++;:;&xx+++xx;++++++++;+++++++x$$&.     
   ;$+x$+;+++;+++++++++++++++++++++X$$+X$+++;&&x:+++$$&&    
  x+++++++++;++++++++++++++++x&+++++;+++++X++++++&+++$$$&   
  x+&+++++;$++++++&:+;+++:++$+++++++$++++&+++;x+++++;+$$&:  
 $++++&&+&++++++++++XX++X++++++;++++&++++$+++x++:x++$&$$&&  
 +++&++++++++++++++++x+++;++++$++++++++++++++++++++$&$$&XX; 
;;;+:;+$++++++x&+++++X:+++x+x+++++;$xx+x+$+:++++++;+$$$x$$& 
&&+++++++++&++++++++++++ ;+++++;+++++++++++x+x+x+x++X$$$$$&.
+;X++++&+++x:+++++++$++++++xxx+++++++:$X.+++++++++++&$$$$$&:
 +$+++&+++++++X;;XX++;;XXx..+++;++++X+++++++++++++;:+$$$;&&:
 $$+X++++++++.++++:X++++++++++;+++++$+++++++X+++++;$;X$$X$X.
 +$+++xx++xx++x++$+++++++++++++$+++++$:+++;$+++x++++$$&$&&; 
 $x++x++++++++;+X+++++$+xX++++++$:++++++xx+++$++$+;&$x$$$x  
 .&++x$+++++++++++++++++++X+++++++x:++$XX:&+++xx;$&$$X&$$+  
  +++:++++:++:;++++++++++++++++;X++++x+x+++++X+X$$&$$$$$&;  
   &++xxxx++++x++++++&++++++++$;++++++;++&+X+++&$&$$XX$$x.  
    :x++++x;:;+x$+++++x$;+++++$x+++$++++++xX++&$&&x&&$$+.   
     ++xx++++x+X+xx;+++++x+x++++;++++;$$$$$Xxx&$$$$$X&+.    
      :xx+x++++x&++;X&;+++++++&++;$$x++;$$$$$$&&$&$$+.      
       .$$x+++;+X+++xX$+;++X++;$$$$$$$$$&$&$$&$$$X$;        
         :&$$:+++++$$&$+.:;x$$X&$$$X$$$$$$$$$$&X$+          
           :$;$&$$$&$$$$$$$$$$&$$$$&$$X$$&$&$$x+.           
             :+$$&$&$$$$$$$$$$$$$$$$$$$$$$$X;.              
                  .:x$X$X$$+;+X$$++++X$$x;                  
                        :;++xxx++++;:.                      
)";

static const char* threadPrompt = "Please provide the desired amount of mining threads: ";
static const char* monitoringPrompt = "Please provide the monitoring server IP if any: ";

static int colorPreTable[] = {
  0,0,0,0,91,
  0,0,0,0,1,
  1,0,0,0,1,
  0
};
static int colorTable[] = {
  0,0,0,36,91,
  0,0,0,0,91,
  32,0,0,0,93,
  37
};

#define CYAN 3
#define RED 4
#define GREEN 10
#define YELLOW 14
#define WHITE 15

#ifdef WIN32
template<typename... Args>
inline void printcf(WORD color, Args... args) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);

    std::ostringstream oss;
    (oss << ... << args);

    std::cout << oss.str() << std::flush;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
}
#else
template<typename... Args>
inline void printcf(int color, Args... args) {
    printf("\e[%d;%dm", colorPreTable[color], colorTable[color]);

    std::ostringstream oss;
    (oss << ... << args);

    std::cout << oss.str() << std::flush;

    printf("\e[%d;%dm", colorPreTable[WHITE], colorTable[WHITE]);
}
#endif


int initialConfigurations();
