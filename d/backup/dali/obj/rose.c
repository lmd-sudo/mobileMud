//  rose.c
#include <armor.h>
inherit HEAD;

void create()
{   set_name("红玫瑰",({"red rose","rose"}));
    set("long", @LONG
                    'M,        .mM'
                     IMIm    ,mIM'
                     ,MI:'IM,mIMm
          'IMmm,    ,IM::::IM::IM,          ,m'
             'IMMIMMIMm::IM:::::IM''==mm ,mIM'
    __      ,mIM::::::MIM:::::::IM::::mIMIM'
 ,mMIMIMIIMIMM::::::::mM::::::::IMIMIMIMMM'
IMM:::::::::IMM::::::M::::::::IIM:::::::MM,
 'IMM::::::::::MM:::M:::::::IM:::::::::::IM,
    'IMm::::::::IMMM:::::::IM:::::::::::::IM,
      'Mm:::::::::IM::::::MM::::::::::::::::IM,
       IM:::::::::IM::::::MM::::::::::::::::::IM,
        MM::::::::IM:::::::IM::::::::::::::::::IM
        'IM::::::::IM:::::::IM:::::::::::::::::IM;.
         'IM::::::::MM::::::::IM::::::::::mmmIMMMMMMMm,.
           IM::::::::IM:::::::IM::::mIMIMM''''. .. 'IMMMM
           'IM::::::::IM::::::mIMIMM''. . . . . .,mM'   'M
           'IM::::::::IM::::::mIMIMM''. . . . . .,mM'   'M
            IMm:::::::IM::::IIMM' . . . . . ..,mMM'
            'IMMIMIMMIMM::IMM' . . . ._.,mMMMMM'
             ,IM'. . .'IMIM'. . . .,mMMMMMMMM'
           ,IM . . . .,IMM'. . . ,mMMMMMMMMM'
         ,M'..,mIMMIMMIMMIMmmmMMMMMMMMMMMM''
           'IM::::::::IM::::::mIMIMM''. . . . . .,mM'   'M
            IMm:::::::IM::::IIMM' . . . . . ..,mMM'
            'IMMIMIMMIMM::IMM' . . . ._.,mMMMMM'
             ,IM'. . .'IMIM'. . . .,mMMMMMMMM'
           ,IM . . . .,IMM'. . . ,mMMMMMMMMM'
         ,M'..,mIMMIMMIMMIMmmmMMMMMMMMMMMM''
         ,M'..,mIMMIMMIMMIMmmmMMMMMMMMMMMM'
         IM.,IMI'''        ''IIMMMMMMMMMMM
        ;IMIM'                  ''IMMMMMMM
        ''                         'IMMMMM
                                     'IMMM
                                      'IMM,
                                       'IMM
                                        'MM,
                                         IMM,              ______   __
                        ______           'IMM__        .mIMMIMMIMMIMMIMM,
                   .,mIMMIMMIMM, ,mIMM,   IMM'''     ,mIM'. . . . 'IM,..M,
                 ,IMMM' . . . 'IMM.\ 'M,  IMM      ,IM'. . . .  / :;IM \ M,
               .mIM' . . .  / .:'IM.\ MM  'MM,    ,M'. . .  / .;mIMIMIM,\ M
              ,IM'. . .  / . .:;,IMIMIMMM  IMM   ,M'. .  / .:mIM''   'IM,:M
             ,IM'. . . / . .:;,mIM'  `'IMM IMM   IM. .  / .mM'         'IMI
            ,IM . .  / . .:;,mIM'      'IMMMMM   MM,.  / ,mM            'M'
            IM'. .  / . .;,mIM'          'IIMMM ,IMIM,.,IM'
            IM'. .  / ..;,mIM'           'IIMMM ,IMM,.,IM'
            IM . . / . .,mIM'              IMMMMMMM' '''
            `IM,.  / ;,mIM'                 IIMMM
             'IMI, /,mIM'                 __IMMM
                'IMMMM'                    ''IMM
                 ''                         IMM
                                            IMM__
                                            IMM__
                                            IMM'''
                                            IMM
                                            IMM
                                          __IMM
                                         '''IMM
                                            IMM
                                            IMM
                                            IMM__
                                            IMM'''
                                            IMM
LONG);
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {  
                set("value",50); 
                set("unit", "朵");
//                set('material', 'cloth');
                set("armor_prop/armor", 1);
        }
        setup();
}

   
