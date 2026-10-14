c1_u8 __fastcall type_is_cv_qualified_stripped(c1_declarator *d)

{
  byte bVar1;
  c1_type *pcVar2;
  
  pcVar2 = d->type;
  while( true ) {
    bVar1 = (byte)pcVar2->code;
    if (((bVar1 & 0x8f) != 0x83) && ((bVar1 & 0x83) != 0x81)) break;
    pcVar2 = pcVar2->base;
  }
  return (pcVar2->flags & 0x60) != 0;
}

