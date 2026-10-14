c1_symbol * __thiscall sym_copy_unlinked(c1_symbol *dst,c1_symbol *sym,int unused)

{
  fe_name **ppfVar1;
  fe_name *pfVar2;
  c1_u8 cVar3;
  c1_u8 cVar4;
  c1_u8 cVar5;
  uint uVar6;
  uint uVar7;
  c1_symbol *pcVar8;
  c1_symbol *pcVar9;
  
  uVar7 = g_symbol_size_table[sym->kind & 0x1f];
  pcVar8 = sym;
  pcVar9 = dst;
  for (uVar6 = uVar7 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    cVar3 = pcVar8->flags1;
    cVar4 = pcVar8->flags2;
    cVar5 = pcVar8->flags3;
    pcVar9->kind = pcVar8->kind;
    pcVar9->flags1 = cVar3;
    pcVar9->flags2 = cVar4;
    pcVar9->flags3 = cVar5;
    pcVar8 = (c1_symbol *)&pcVar8->flags4;
    pcVar9 = (c1_symbol *)&pcVar9->flags4;
  }
  for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
    pcVar9->kind = pcVar8->kind;
    pcVar8 = (c1_symbol *)&pcVar8->flags1;
    pcVar9 = (c1_symbol *)&pcVar9->flags1;
  }
  dst->kind = dst->kind & 0xdf;
  ppfVar1 = &dst->name;
  if ((sym->kind & 0x1f) == 4) {
    if (ppfVar1 != (fe_name **)0x0) {
      pfVar2 = sym->name;
      dst->next = (c1_sym_link *)0x0;
      *ppfVar1 = pfVar2;
      dst->tag_members = sym->tag_members;
    }
  }
  else if (ppfVar1 != (fe_name **)0x0) {
    *ppfVar1 = sym->name;
    dst->next = (c1_sym_link *)0x0;
    return dst;
  }
  return dst;
}

