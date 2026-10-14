void __fastcall conv_rule_function_name_to_pointer(c1_conversion *conv)

{
  c1_u8 cVar1;
  c1_u8 cVar2;
  c1_type *pcVar3;
  int iVar4;
  byte bVar5;
  c1_node *pcVar6;
  c1_type *pcVar7;
  c1_symbol *pcVar8;
  c1_symbol *set;
  c1_symbol *sym;
  c1_conversion *conv_00;
  c1_conversion *pcStack_4;
  
  pcStack_4 = conv;
  pcVar6 = expr_strip_to_function_ref(conv->expr,(uint *)&pcStack_4);
  conv->function_ref = pcVar6;
  if (pcVar6 == (c1_node *)0x0) {
    conv->rank = 0x70;
    conv->note = 0x178a;
    return;
  }
  pcVar8 = pcVar6->left;
  conv->overload_set = pcVar8;
  set = (c1_symbol *)0x0;
  sym = pcVar8;
  if ((pcVar8->kind & 0x1f) == 0x12) {
    sym = *(c1_symbol **)(*(int *)pcVar8->type + 8);
    set = pcVar8;
  }
  bVar5 = sym->kind & 0x1f;
  if (((((bVar5 != 0x10) && (bVar5 != 7)) && (bVar5 != 6)) &&
      (((bVar5 != 0x11 && (bVar5 != 8)) && (bVar5 != 0x1b)))) &&
     ((bVar5 != 0x1a ||
      (((bVar5 = **(byte **)sym->type & 0x1f, bVar5 != 0x10 && (bVar5 != 7)) &&
       ((bVar5 != 6 && (((bVar5 != 0x11 && (bVar5 != 8)) && (bVar5 != 0x1b)))))))))) {
    conv->rank = 0x70;
    conv->note = 0x178a;
    return;
  }
  pcVar7 = type_base(conv->target);
  pcVar8 = ovl_select_function_for_target_type(sym,pcVar7,0,'\0');
  (conv->via).function = pcVar8;
  if (pcVar8 != (c1_symbol *)0x0) {
    pcVar7 = pcVar8->type;
    if (((pcVar7->code & 0x8f) == 0x85) && ((((pcVar7->extra).cls)->flags5 & 1) == 0)) {
      pcVar7 = type_member_function_pointer_for_set(pcVar7,set);
    }
    else {
      pcVar7 = type_member_pointer_to_2(pcVar7,'\x01');
    }
    conv_00 = (c1_conversion *)g_arenas[5].cur;
    g_arenas[5].cur = g_arenas[5].cur + 0x50;
    if (g_arenas[5].end < g_arenas[5].cur) {
      arena_grow(g_arenas + 5);
    }
    if (conv_00 == (c1_conversion *)0x0) {
      conv_00 = (c1_conversion *)0x0;
    }
    else {
      pcVar3 = conv->target;
      cVar1 = conv->mode;
      cVar2 = conv->op;
      *(c1_u8 *)((int)conv_00 + 2) = conv->flags;
      conv_00->op = cVar2;
      *(c1_u8 *)((int)conv_00 + 1) = cVar1;
      *(c1_u8 *)((int)conv_00 + 4) = '\0';
      *(c1_u8 *)((int)conv_00 + 5) = '\0';
      *(c1_u8 *)((int)conv_00 + 6) = '\0';
      *(c1_u8 *)((int)conv_00 + 7) = '\0';
      *(c1_type **)((int)conv_00 + 8) = pcVar7;
      *(c1_type **)((int)conv_00 + 0xc) = pcVar3;
      conv_compute_conversion(conv_00);
    }
    conv->first = conv_00;
    if ((conv_00->flags4e & 1) != 0) {
      iVar4 = conv_00->rank;
      conv->build = conv_build_resolved_function_address;
      conv->rank = iVar4;
      conv->note_fn = diag_note_overload_resolved;
      conv->flags4e = conv->flags4e | 0x80;
      return;
    }
  }
  conv->rank = 0x70;
  conv->note = 0x178c;
  return;
}

