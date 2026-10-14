c1_symbol * __thiscall sym_copy_unlinked(c1_symbol *dst,c1_symbol *sym,int arena)

{
  fe_name *pfVar1;
  c1_u8 cVar2;
  c1_u8 cVar3;
  c1_u8 cVar4;
  byte bVar5;
  uint uVar6;
  uint uVar7;
  c1_symbol *pcVar8;
  c1_symbol *pcVar9;
  
  uVar7 = g_symbol_size_table[sym->kind & 0x1f];
  pcVar8 = sym;
  pcVar9 = dst;
  for (uVar6 = uVar7 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    cVar2 = pcVar8->flags1;
    cVar3 = pcVar8->flags2;
    cVar4 = pcVar8->flags3;
    pcVar9->kind = pcVar8->kind;
    pcVar9->flags1 = cVar2;
    pcVar9->flags2 = cVar3;
    pcVar9->flags3 = cVar4;
    pcVar8 = (c1_symbol *)&pcVar8->flags4;
    pcVar9 = (c1_symbol *)&pcVar9->flags4;
  }
  for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
    pcVar9->kind = pcVar8->kind;
    pcVar8 = (c1_symbol *)&pcVar8->flags1;
    pcVar9 = (c1_symbol *)&pcVar9->flags1;
  }
  dst->kind = dst->kind & 0xdf;
  bVar5 = sym->kind & 0x1f;
  if (bVar5 == 4) {
    if (&dst->name != (fe_name **)0x0) {
      pfVar1 = sym->name;
      dst->next = (c1_symbol *)0x0;
      dst->name = pfVar1;
      dst->x28 = sym->x28;
    }
  }
  else if ((bVar5 < 0x10) || (0x11 < bVar5)) {
    if (&dst->name != (fe_name **)0x0) {
      dst->name = sym->name;
      dst->next = (c1_symbol *)0x0;
      return dst;
    }
  }
  else if (&dst->name != (fe_name **)0x0) {
    pfVar1 = sym->name;
    dst->next = (c1_symbol *)0x0;
    dst->name = pfVar1;
    dst->type = sym->type;
    return dst;
  }
  return dst;
}

