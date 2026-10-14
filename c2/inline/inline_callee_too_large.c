int __fastcall inline_callee_too_large(c2_function *callee,c2_tuple *call,c2_tuple *entry)

{
  c2_operand **ppcVar1;
  uint8_t uVar2;
  ushort uVar3;
  c2_operand *pcVar4;
  c2_operand *pcVar5;
  c2_symbol *pcVar6;
  c2_tuple *pcVar7;
  c2_operand *pcVar8;
  c2_tuple *pcVar9;
  uint32_t uVar10;
  bool bVar11;
  c2_operand *pcVar12;
  c2_tuple *pcVar13;
  int iVar14;
  int local_18;
  int local_14;
  
  iVar14 = 0;
  pcVar4 = call->src->next;
  for (pcVar5 = pcVar4; pcVar5 != (c2_operand *)0x0; pcVar5 = pcVar5->next) {
    if (((1 << (pcVar5->kind & 0x1f) & 6U) != 0) && (pcVar5->sym->def != (c2_tuple *)0x0)) {
      iVar14 = iVar14 + 1;
    }
  }
  local_14 = (iVar14 + 2) * g_opt_vol;
  if (((g_cur_function->flags & 0x18000) == 0) || (g_opt_eh_enabled == 0)) {
    bVar11 = false;
  }
  else {
    local_14 = local_14 + g_opt_vol * 2;
    bVar11 = true;
  }
  local_18 = 0;
  pcVar13 = callee->cfg->first->head;
  do {
    if (pcVar13 == (c2_tuple *)0x0) {
      return 0;
    }
    uVar2 = pcVar13->kind;
    if (uVar2 == '\f') {
      local_18 = local_18 + 1;
      if (((((pcVar13->op == 0x17d) && (pcVar5 = pcVar13->src, pcVar5->kind == '\x02')) &&
           (pcVar6 = pcVar5->sym, pcVar6->cls == '\x05')) &&
          ((pcVar5 = pcVar5->next, pcVar5->kind == '\a' &&
           (pcVar7 = pcVar13->next, pcVar7->op == 0x185)))) &&
         (pcVar6->storage->part_next == (c2_symbol *)0x0)) {
        pcVar12 = pcVar4;
        if (callee->struct_return != (c2_fe_symbol *)0x0) {
          pcVar12 = pcVar4->next;
        }
        for (pcVar8 = entry->src;
            ((pcVar12 != (c2_operand *)0x0 && ((1 << (pcVar12->kind & 0x1f) & 6U) != 0)) &&
            ((pcVar9 = pcVar12->sym->def, pcVar9 != (c2_tuple *)0x0 &&
             (((uVar10 = pcVar9->op, uVar10 == 0x15a || (uVar10 == 0x16a)) &&
              (pcVar8->sym != pcVar6)))))); pcVar8 = pcVar8->next) {
          pcVar12 = pcVar12->next;
        }
        if (((pcVar8 != (c2_operand *)0x0) && (pcVar8->sym == pcVar6)) &&
           ((pcVar12 = pcVar12->sym->def->src, pcVar12->kind == '\a' &&
            ((uVar3 = pcVar13->type, pcVar12->type == uVar3 &&
             (iVar14 = fold_constant_compare
                                 ((uint)((uVar3 & 0xf000) == 0x1000),uVar3 & 0xfff,(pcVar12->u18).lo
                                  ,pcVar12->tag,(pcVar5->u18).lo,pcVar5->tag,(uint8_t)pcVar7->type),
             iVar14 != 0)))))) {
          ppcVar1 = &pcVar7->src;
          for (; pcVar7 != (c2_tuple *)0x0; pcVar7 = pcVar7->next) {
            if (pcVar7 == *(c2_tuple **)((int)&(*ppcVar1)->sym->u30 + 2)) {
              if (pcVar7 != (c2_tuple *)0x0) {
                pcVar13 = pcVar7;
              }
              break;
            }
          }
        }
      }
    }
    else {
      if (uVar2 == '\x0e') {
        if (bVar11) {
          bVar11 = false;
          local_14 = local_14 + g_opt_vol * -2;
        }
      }
      else if (uVar2 != '\x12') goto LAB_1079484b;
      local_18 = local_18 + 2;
    }
LAB_1079484b:
    if (local_14 < local_18) {
      return 1;
    }
    pcVar13 = pcVar13->next;
  } while( true );
}

