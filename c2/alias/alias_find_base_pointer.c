c2_symbol * __fastcall alias_find_base_pointer(c2_symbol *base_temp)

{
  byte bVar1;
  c2_tuple *pcVar2;
  c2_operand *pcVar3;
  c2_symbol *pcVar4;
  c2_symbol *pcVar5;
  bool bVar6;
  
  pcVar2 = base_temp->def;
  pcVar5 = (c2_symbol *)0x0;
  if ((pcVar2->kind == '\x0e') || (pcVar2->kind == '\x12')) {
    return g_alias_unknown_base;
  }
  pcVar3 = pcVar2->src;
  do {
    if (pcVar3 == (c2_operand *)0x0) {
      return pcVar5;
    }
    if ((pcVar3->flags & 0x20) == 0) {
      bVar1 = pcVar3->kind;
      if (((1 << (bVar1 & 0x1f) & 6U) == 0) || (pcVar3->sym->def == (c2_tuple *)0x0)) {
        if (bVar1 == 2) {
          pcVar4 = pcVar3->sym;
          if ((pcVar4->flags6 & 8) != 0) {
            return pcVar4;
          }
          if ((pcVar4->fe != (c2_fe_symbol *)0x0) && (((byte)pcVar4->fe->storage & 0xf) == 3)) {
            return pcVar4;
          }
        }
        else if (bVar1 == 6) {
          pcVar4 = (pcVar3->u18).reg;
          if ((pcVar4->fe != (c2_fe_symbol *)0x0) && (((byte)pcVar4->fe->storage & 0xf) == 3)) {
            return (pcVar3->u18).reg;
          }
          bVar6 = pcVar5 != (c2_symbol *)0x0;
          pcVar5 = pcVar4;
          if ((bVar6) && (pcVar2->op != 0x16d)) {
            return g_alias_unknown_base;
          }
        }
      }
      else {
        pcVar4 = alias_find_base_pointer(pcVar3->sym);
        if (pcVar4 != (c2_symbol *)0x0) {
          if ((pcVar4->flags6 & 8) != 0) {
            return pcVar4;
          }
          if ((pcVar4->fe != (c2_fe_symbol *)0x0) && (((byte)pcVar4->fe->storage & 0xf) == 3)) {
            return pcVar4;
          }
          bVar6 = pcVar5 != (c2_symbol *)0x0;
          pcVar5 = pcVar4;
          if (bVar6) {
            return g_alias_unknown_base;
          }
        }
      }
    }
    pcVar3 = pcVar3->next;
  } while( true );
}

