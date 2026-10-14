int __fastcall
relax_widen_branch(c2_tuple **cursor,int32_t offset_after_branch,char pass,int32_t growth_this_pass,
                  c2_fe_symbol *section)

{
  byte bVar1;
  c2_tuple *t;
  c2_symbol *pcVar2;
  int iVar3;
  c2_symbol *pcVar4;
  uint32_t uVar5;
  uint uVar6;
  
  t = *cursor;
  if ((t->src->kind == '\x04') && (pcVar2 = t->src->sym, pcVar2->cls == '\x03')) {
    iVar3 = *(int *)((int)&pcVar2->u30 + 2);
    pcVar4 = pcVar2->part_next;
    if (*(char *)(iVar3 + 0x12) != pass) {
      pcVar4 = (c2_symbol *)((int)&pcVar4->fe + growth_this_pass);
    }
    if ((section == (c2_fe_symbol *)0x0) || (pcVar2->offset == section->id)) {
      if (((int)pcVar4 - offset_after_branch < 0x80) && (-0x81 < (int)pcVar4 - offset_after_branch))
      {
        return 0;
      }
    }
    else {
      note_symbol_referenced(*(c2_fe_symbol **)(iVar3 + 0x18));
    }
    uVar6 = t->op;
    if (uVar6 < 0x115) {
      if ((((uVar6 != 0x114) && (0xe < uVar6)) && (0x10 < uVar6)) && (uVar6 == 0x113)) {
        uVar5 = 0xf;
LAB_1073ea2f:
        bVar1 = t->flags12;
        t->op = uVar5;
        uVar6 = tuple_encoded_length(t);
        t->flags12 = (uint8_t)uVar6;
        return (uVar6 & 0xff) - (uint)bVar1;
      }
    }
    else if (uVar6 == 0x115) {
      uVar5 = 0x10;
      goto LAB_1073ea2f;
    }
  }
  return 0;
}

