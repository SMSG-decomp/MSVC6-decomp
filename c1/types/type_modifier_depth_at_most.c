int __cdecl type_modifier_depth_at_most(c1_type *declared,c1_type *defined)

{
  char cVar1;
  
  cVar1 = (char)defined->code;
  while( true ) {
    if (-1 < cVar1) {
      return 0;
    }
    declared = declared->base;
    defined = defined->base;
    if (-1 < (char)declared->code) break;
    cVar1 = (char)defined->code;
  }
  return 1;
}

