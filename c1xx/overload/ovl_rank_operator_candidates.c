uint __fastcall ovl_rank_operator_candidates(c1_ovl_resolution *res)

{
  byte bVar1;
  c1_ovl_candidate *cand;
  uint uVar2;
  c1_node *pcVar3;
  c1_type *pcVar4;
  c1_type *pcVar5;
  byte bVar6;
  c1_conversion *conv;
  c1_conversion *conv_00;
  c1_node *local_28;
  c1_type *local_24;
  c1_type local_20;
  c1_type local_10;
  
  pcVar3 = (res->extra).right;
  if ((pcVar3 != (c1_node *)0x0) && (pcVar3->type->code == 0x80e)) {
    pcVar3 = expr_resolve_address_of_overload(pcVar3);
    (res->extra).right = pcVar3;
LAB_104a773a:
    return (uint)pcVar3 & 0xffffff00;
  }
  for (cand = res->head; cand != (c1_ovl_candidate *)0x0; cand = cand->next) {
    local_28 = res->args;
    conv = cand->conversions;
    bVar6 = ~cand->flags & 4 | res->flags & 0x60;
    ovl_set_failure_reason(res,8,0);
    if ((cand->flags & 4) == 0) {
      if (((cand->function->flags1 & 4) == 0) ||
         ((*(byte *)((int)&cand->function->tail + 8) & 1) == 0)) {
        local_24 = *cand->param_cursor;
        cand->param_cursor = cand->param_cursor + 1;
      }
      else {
        local_24 = cand->object_type;
        local_28 = res->args;
        bVar6 = bVar6 | 0xa0;
      }
    }
    else {
      local_24 = cand->builtin_left;
    }
    if (conv == (c1_conversion *)0x0) {
      conv = (c1_conversion *)0x0;
    }
    else {
      conv->op = '`';
      conv->mode = '\x03';
      conv->flags = bVar6;
      conv->expr = local_28;
      if (local_28 == (c1_node *)0x0) {
        local_20.base = (c1_type *)0x0;
        local_20.debug_index = 0;
        local_20.flags = 0;
        local_20.extra.cls = (c1_symbol *)0x0;
        local_20.code = 0x80f;
        pcVar4 = type_intern(&local_20);
      }
      else {
        pcVar4 = local_28->type;
      }
      conv->source = pcVar4;
      conv->target = local_24;
      conv_compute_conversion(conv);
    }
    uVar2 = ovl_check_argument_conversion(res,conv,cand,0,local_28,3);
    pcVar3 = (c1_node *)0x0;
    if (uVar2 == 0) goto LAB_104a773a;
    pcVar3 = (c1_node *)0x0;
    if (uVar2 == 1) break;
    pcVar3 = (c1_node *)0x0;
    if ((uVar2 != 3) && (pcVar3 = (c1_node *)0x0, (res->extra).right != (c1_node *)0x0)) {
      ovl_set_failure_reason(res,9,0);
      conv_00 = conv + 1;
      cand->argument = cand->argument + 1;
      bVar6 = cand->flags;
      if ((bVar6 & 4) == 0) {
        pcVar4 = *cand->param_cursor;
      }
      else {
        pcVar4 = g_type_int;
        if ((cand->builtin_right->code & 0x100) == 0) {
          pcVar4 = cand->builtin_right;
        }
      }
      if (conv_00 == (c1_conversion *)0x0) {
        conv_00 = (c1_conversion *)0x0;
      }
      else {
        bVar1 = res->flags;
        pcVar3 = (res->extra).right;
        conv_00->op = '`';
        conv[1].flags = ~bVar6 & 4 | bVar1 & 0x60;
        conv[1].mode = '\x03';
        conv[1].expr = pcVar3;
        if (pcVar3 == (c1_node *)0x0) {
          local_10.base = (c1_type *)0x0;
          local_10.debug_index = 0;
          local_10.flags = 0;
          local_10.extra.cls = (c1_symbol *)0x0;
          local_10.code = 0x80f;
          pcVar5 = type_intern(&local_10);
          conv[1].source = pcVar5;
          conv[1].target = pcVar4;
          conv_compute_conversion(conv_00);
        }
        else {
          conv[1].source = pcVar3->type;
          conv[1].target = pcVar4;
          conv_compute_conversion(conv_00);
        }
      }
      uVar2 = ovl_check_argument_conversion(res,conv_00,cand,1,(res->extra).right,3);
      pcVar3 = (c1_node *)0x0;
      if (uVar2 == 0) goto LAB_104a773a;
      pcVar3 = (c1_node *)0x0;
      if (uVar2 == 1) break;
      pcVar3 = (c1_node *)(uVar2 - 3);
    }
  }
  return CONCAT31((int3)((uint)pcVar3 >> 8),1);
}

