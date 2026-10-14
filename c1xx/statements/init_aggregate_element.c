int __cdecl init_aggregate_element(c1_symbol *sym,int *value,int conv)

{
  char cVar1;
  c1_type *pcVar2;
  c1_type *pcVar3;
  bool bVar4;
  c1_node *pcVar5;
  int iVar6;
  c1_symbol *pcVar7;
  byte bVar8;
  ushort uVar9;
  c1_symbol *local_8;
  int local_4;
  
  bVar4 = false;
  local_8 = (c1_symbol *)0x0;
  local_4 = 0;
  pcVar5 = tree_strip_casts_and_segment_bases((c1_node *)*value);
  if (((pcVar5->kind & 7) == 5) &&
     ((((bVar8 = sym->kind & 0x1f, bVar8 == 0 || (0xe < bVar8)) || (bVar8 == 5)) ||
      (((sym->type->code & 0x200) == 0 || ((((sym->type->extra).cls)->flags1 & 0x10) != 0x10)))))) {
    bVar4 = true;
    iVar6 = init_is_char_array_string_init(sym,pcVar5);
    if (iVar6 != 0) {
      *value = (int)pcVar5;
      return 1;
    }
  }
  if (*value == 0) {
    return 0;
  }
  if ((*(byte *)(conv + 0x4e) & 1) == 0) {
    return 0;
  }
  iVar6 = init_check_member_kind((c1_conversion *)conv);
  if ((char)iVar6 != '\0') {
    pcVar5 = (c1_node *)*value;
    pcVar2 = sym->type;
    pcVar3 = pcVar5->type;
    if (((((pcVar3 != pcVar2) && ((char)pcVar2->code < '\0')) &&
         ((uVar9 = pcVar2->code & 0x8f, uVar9 == 0x86 || (uVar9 == 0x82)))) &&
        (((uVar9 = pcVar2->flags & 0x18, uVar9 == 0x18 || (uVar9 == 8)) &&
         (pcVar2 = ((pcVar2->extra).cls)->type, (char)pcVar2->code < '\0')))) &&
       ((pcVar2 != (c1_type *)0x0 && ((pcVar5->kind & 0x80) == 0)))) {
      if ((pcVar5->kind & 7) != 3) {
        return 0;
      }
      cVar1 = (char)pcVar3->code;
      while (cVar1 < '\0') {
        pcVar3 = pcVar3->base;
        cVar1 = (char)pcVar3->code;
      }
      if ((pcVar3->code & 0xfff) != 0x13) {
        return 0;
      }
    }
    if (((!bVar4) && ((pcVar5->kind & 7) != 3)) &&
       ((iVar6 = init_split_address_constant(pcVar5,&local_8,&local_4), iVar6 == 0 ||
        (((((local_8 != (c1_symbol *)0x0 && (bVar8 = local_8->kind & 0x1f, bVar8 != 0)) &&
           (bVar8 < 0xf)) && (bVar8 != 5)) &&
         ((((bVar8 == 0xe && ((local_8->entity & 0xffffff) == 6)) ||
           (((local_8->flags23 & 1) != 0 &&
            (pcVar7 = sym_segment_record(local_8), (pcVar7->kind & 0x1f) != 0xe)))) ||
          ((((local_8->storage & 7) == 4 &&
            (((bVar8 = sym->kind & 0x1f, bVar8 == 3 || (bVar8 == 2)) || ((sym->storage & 7) == 3))))
           || (((((local_8->flags22 & 2) != 0 && (bVar8 = local_8->kind & 0x1f, bVar8 != 7)) &&
                (bVar8 != 8)) || ((local_8->flags22 & 8) != 0)))))))))))) {
      return 0;
    }
    return 1;
  }
  return 0;
}

