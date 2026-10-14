void __cdecl conv_warn_different_bases(c1_u8 op,c1_type *type,c1_type *type2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  c1_symbol *pcVar4;
  byte bVar5;
  c1_symbol *pcVar6;
  
  if (((type2->code & 0x8f) != 0x83) || ((type2->flags & 8) == 0)) {
    bVar1 = (byte)type2->flags;
    bVar5 = bVar1 & 0x18;
    bVar2 = (byte)type->flags;
    bVar3 = bVar2 & 0x18;
    if (((((bVar2 & 8) != 0) || (((bVar1 & 8) != 0 && ((bVar2 & 8) != 0)))) && ((bVar1 & 8) != 0))
       && ((bVar5 != 8 && (bVar3 != 8)))) {
      if (bVar5 != bVar3) {
        diag_warning(1,0x7b);
        return;
      }
      if (bVar3 == 0x18) {
        pcVar6 = (type->extra).sym;
      }
      else {
        pcVar6 = (c1_symbol *)0x0;
      }
      if (bVar5 == 0x18) {
        pcVar4 = (type2->extra).sym;
      }
      else {
        pcVar4 = (c1_symbol *)0x0;
      }
      if (pcVar6 != pcVar4) {
        diag_warning(1,0x77,pcVar6,pcVar4);
      }
    }
  }
  return;
}

