int __fastcall count_address_sources(c2_symbol *base_temp,c2_symbol **out_base)

{
  byte bVar1;
  c2_tuple *pcVar2;
  c2_operand *pcVar3;
  c2_symbol *base_temp_00;
  int iVar4;
  int iVar5;
  
  pcVar2 = base_temp->def;
  iVar5 = 0;
  if (((pcVar2->kind == '\x0e') || (pcVar2->kind == '\x12')) || (pcVar2->op == 0x17d)) {
    return 0;
  }
  pcVar3 = pcVar2->src;
  do {
    if (pcVar3 == (c2_operand *)0x0) {
      return iVar5;
    }
    if ((pcVar3->flags & 0x20) == 0) {
      bVar1 = pcVar3->kind;
      if (bVar1 == 3) {
        iVar5 = iVar5 + 1;
        *out_base = pcVar3->sym->storage;
      }
      else if (bVar1 == 5) {
        if ((1 << (pcVar3->base->kind & 0x1f) & 6U) != 0) {
          base_temp_00 = pcVar3->base->sym;
          pcVar2 = base_temp_00->def;
          goto joined_r0x1078a639;
        }
      }
      else if ((1 << (bVar1 & 0x1f) & 6U) != 0) {
        base_temp_00 = pcVar3->sym;
        pcVar2 = base_temp_00->def;
joined_r0x1078a639:
        if (pcVar2 != (c2_tuple *)0x0) {
          iVar4 = count_address_sources(base_temp_00,out_base);
          iVar5 = iVar5 + iVar4;
        }
      }
    }
    pcVar3 = pcVar3->next;
  } while( true );
}

