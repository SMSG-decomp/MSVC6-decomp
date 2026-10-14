void __thiscall ovl_report_call_failure(c1_ovl_resolution *res,c1_ovl_candidate *cand,c1_node *node)

{
  bool bVar1;
  byte bVar2;
  char cVar3;
  ushort uVar4;
  c1_builtin_operator_row *pcVar5;
  c1_type *pcVar6;
  c1_node *pcVar7;
  c1_sym_link *arg_link;
  c1_symbol *arg_sym;
  c1_symbol *pcVar8;
  c1_sym_link *member_link;
  c1_u32 cVar9;
  c1_symbol *sym;
  c1_type *pcVar10;
  uint uVar11;
  c1_symbol *local_8;
  c1_symbol *local_4;
  c1_sym_link *arg_link_2;
  
  if ((res->flags & 1) == 0) {
    return;
  }
  if ((res->flags & 2) != 0) {
    if (res->failure == 1) {
      return;
    }
    if (((res->failure == 8) && (res->op == '1')) && ((res->extra).right == (c1_node *)0x0)) {
      return;
    }
  }
  pcVar8 = res->set;
  cVar9 = res->nargs;
  sym = (c1_symbol *)0x0;
  local_4 = (c1_symbol *)0x0;
  bVar1 = false;
  if (pcVar8 == (c1_symbol *)0x0) {
    pcVar5 = ovl_builtin_candidates_for_operator(res->op);
    local_8 = (c1_symbol *)pcVar5->name->text;
  }
  else {
    if ((pcVar8->kind & 0x1f) == 0x1b) {
      pcVar8 = (c1_symbol *)**(undefined4 **)pcVar8->type;
    }
    bVar2 = pcVar8->kind & 0x1f;
    if (((bVar2 == 0x10) || (sym = pcVar8, bVar2 == 0x11)) &&
       ((sym = (c1_symbol *)&pcVar8->type[-1].extra, cand != (c1_ovl_candidate *)0x0 &&
        (pcVar8 = cand->function, pcVar8 != (c1_symbol *)0x0)))) {
      sym = pcVar8;
      local_4 = pcVar8;
    }
    local_8 = (c1_symbol *)diag_symbol_display_name(sym);
    if ((sym->flags1 & 4) != 0) {
      cVar9 = cVar9 - 1;
    }
    if ((sym->flags1 & 0x10) == 0x10) {
      bVar1 = true;
    }
  }
  if (((node != (c1_node *)0x0) && (cVar9 == 1)) && (node->op == '`')) {
    node = node->left;
  }
  switch(res->failure) {
  case 0:
    diag_error(0x208,sym);
    return;
  case 1:
    if (bVar1) {
      if (cVar9 == 0) {
        diag_error(0x200,sym);
        return;
      }
      if (cVar9 != 1) goto LAB_104a6840;
      pcVar10 = node->type;
      uVar11 = 2;
      pcVar6 = type_base(cand->object_type);
      cVar3 = type_compare(pcVar10,pcVar6,uVar11);
      if (cVar3 != '\0') {
        diag_error(0x22e,node->type,(node->type->extra).cls);
        return;
      }
    }
    else {
LAB_104a6840:
      if (cVar9 == 0) {
        if (res->count != 1) goto LAB_104a688b;
        if ((*(byte *)((int)&sym->tail + 9) & 0x20) != 0) {
          diag_error(0x39f,local_8);
          return;
        }
      }
    }
    if (res->count == 1) {
      diag_error(0x294,local_8,cVar9);
      return;
    }
LAB_104a688b:
    diag_error(0x295,local_8,cVar9);
    return;
  case 2:
    if (res->count == 1) {
      diag_begin_global(g_token_position);
      pcVar8 = local_4;
      if (local_4 == (c1_symbol *)0x0) {
        pcVar8 = local_8;
      }
      pcVar10 = node->type;
      pcVar6 = type_strip_cv_qualifiers(cand->object_type);
      diag_error(0x296,(int)(char)((-(local_4 != (c1_symbol *)0x0) & 0xd1U) + 0x73),pcVar8,pcVar10,
                 pcVar6);
      conv_report_cannot_convert(cand->conversions,'\0');
      diag_end_global();
      return;
    }
    diag_error(0x297,local_8,res->count);
    return;
  case 3:
    if ((bVar1) && (cVar9 == 1)) {
      pcVar10 = node->type;
      uVar11 = 2;
      pcVar6 = type_base(cand->object_type);
      cVar3 = type_compare(pcVar10,pcVar6,uVar11);
      if (cVar3 != '\0') {
        diag_error(0x22e,node->type,(node->type->extra).cls);
        return;
      }
    }
    if (node == (c1_node *)0x0) {
      pcVar10 = (c1_type *)0x0;
    }
    else {
      pcVar10 = node->type;
      if ((pcVar10->code == 0x80c) || (pcVar10->code == 0x80e)) {
        pcVar7 = tree_strip_address_of(node);
        if (pcVar7->op == 'S') {
          pcVar7 = pcVar7->right;
        }
        arg_link = pcVar7->left;
        if (((uint)arg_link->name & 0x1f) == 0x12) {
          arg_link = (c1_sym_link *)(arg_link[1].next)->name->flags;
        }
        arg_link = (c1_sym_link *)&arg_link->position;
        member_link = (c1_sym_link *)0x0;
        if (arg_link != (c1_sym_link *)0x0) {
          bVar2 = *(byte *)&arg_link->name & 0x1f;
          if ((((bVar2 != 7) && (bVar2 != 8)) && (bVar2 != 6)) &&
             (((uint)arg_link->name & 0x1f) != 0x1a)) {
            arg_link = arg_link[1].next;
          }
          if (arg_link != (c1_sym_link *)0x0) {
            member_link = arg_link;
          }
        }
        arg_sym = (c1_symbol *)&member_link[-1].position;
        if ((member_link[-1].position & 0x1f) == 0x1a) {
          arg_sym = ((member_link->type).alias)->target;
        }
        pcVar10 = arg_sym->type;
      }
    }
    if ((res->count != 1) && (res->failure_count != 1)) {
      diag_error(0x299,local_8,res->failure_count,res->failure_argument,pcVar10);
      return;
    }
    uVar4 = tmpl_type_find_parameter(cand->param_type,0,0);
    if (uVar4 != 0) {
      diag_error(0x29e,local_8,res->failure_argument,pcVar10);
      return;
    }
    diag_begin_global(g_token_position);
    pcVar8 = local_4;
    if (local_4 == (c1_symbol *)0x0) {
      pcVar8 = local_8;
    }
    diag_error(0x298,(int)(char)((-(local_4 != (c1_symbol *)0x0) & 0xd1U) + 0x73),pcVar8,
               res->failure_argument,pcVar10,cand->param_type);
    if (cand->function != (c1_symbol *)0x0) {
      conv_report_cannot_convert(cand->conversions + cand->argument,'\0');
    }
    diag_end_global();
    return;
  case 4:
    diag_error(0x29a,local_8,res->failure_count);
    return;
  case 5:
    diag_error(0x29b,local_8,res->failure_count);
    return;
  case 6:
    diag_error(0x29c,local_8);
    return;
  case 7:
    diag_error(0x251,(uint)res->op);
    return;
  case 8:
    if ((node->kind & 8) == 0) {
      diag_error(0x2a6,(uint)res->op,node->type);
      return;
    }
    break;
  case 9:
    if ((node->kind & 8) == 0) {
      diag_error(0x2a7,(uint)res->op,node->type);
    }
  }
  return;
}

