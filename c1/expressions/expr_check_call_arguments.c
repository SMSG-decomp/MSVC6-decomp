c1_node * __cdecl expr_check_call_arguments(c1_node *node,int mode)

{
  char cVar1;
  int iVar2;
  c1_node *pcVar3;
  c1_node *pcVar4;
  fe_arena *a;
  c1_type *pcVar5;
  c1_type *extraout_ECX;
  byte bVar6;
  ushort uVar7;
  int iVar8;
  char *pcVar9;
  
  a = g_arenas + g_expr_arena_index;
  pcVar3 = (c1_node *)a->cur;
  pcVar4 = (c1_node *)g_arenas[g_expr_arena_index].end;
  a->cur = &pcVar3[1].op;
  if (pcVar4 < pcVar3 + 1) {
    arena_grow(a);
  }
  pcVar3->op = '`';
  pcVar3->kind = '\x02';
  pcVar3->left = node;
  if (mode != 0) {
    if (mode != 1) {
      pcVar3->type = node->type;
      return pcVar3;
    }
LAB_1061df2f:
    pcVar3->type = g_type_none;
    return pcVar3;
  }
  if (g_call_context == (c1_call_context *)0x0) {
    return (c1_node *)0x0;
  }
  g_call_context->nargs = g_call_context->nargs + 1;
  if (((byte)node->type->code >> 6 & 1) != 0) {
    if (g_call_context->call_depth < 2) {
      diag_error(0x5f,g_call_context->name,g_call_context->nargs);
      pcVar3->type = g_type_int;
      return pcVar3;
    }
    diag_error(0xae,g_call_context->name,g_call_context->nargs,g_call_context->call_depth);
    pcVar3->type = g_type_int;
    return pcVar3;
  }
  pcVar5 = (c1_type *)g_call_context->nformals;
  if ((((int)pcVar5 < 1) || (pcVar5 = *g_call_context->formal, pcVar5->code == 0x80d)) ||
     ((g_call_context->flags & 2) != 0)) {
    if (((g_call_context->flags & 1) != 0) && ((node->type->code & 0x300) != 0)) {
      diag_error(0x126,g_call_context->name,g_call_context->nargs);
      pcVar5 = extraout_ECX;
    }
    bVar6 = g_call_context->flags;
    if (((bVar6 & 2) == 0) || ((bVar6 & 8) == 0)) {
      if ((g_call_context->nformals < 1) && (((bVar6 & 4) == 0 && ((bVar6 & 8) != 0)))) {
        pcVar3 = expr_check_too_many_arguments
                           (CONCAT31((int3)((uint)pcVar5 >> 8),bVar6),g_call_context,pcVar3,node);
        return pcVar3;
      }
    }
    else if ((bVar6 & 0x10) == 0) {
      diag_warning(1,0x57,g_call_context->name);
      g_call_context->flags = g_call_context->flags | 0x10;
    }
    pcVar5 = node->type;
    bVar6 = (byte)pcVar5->code;
    if ((char)bVar6 < '\0') {
      if ((bVar6 & 0x8f) == 0x86) {
        pcVar3->type = pcVar5;
        return pcVar3;
      }
      uVar7 = pcVar5->flags & 0x18;
      if ((uVar7 == 0x18) || (uVar7 == 8)) {
        if ((g_call_context->flags & 8) == 0) {
          iVar2 = g_call_context->nargs;
          pcVar9 = g_call_context->name;
          iVar8 = 0x17;
        }
        else {
          if ((g_call_context->flags & 4) == 0) goto LAB_1061df2f;
          iVar2 = g_call_context->nargs;
          pcVar9 = g_call_context->name;
          iVar8 = 0x19;
        }
        diag_warning(1,iVar8,pcVar9,iVar2);
      }
    }
    goto LAB_1061df2f;
  }
  uVar7 = pcVar5->flags & 0x18;
  if ((uVar7 == 0x18) || (uVar7 == 8)) {
    pcVar4 = type_based_pointer_from_node(pcVar5,pcVar3->left);
    pcVar3->left = pcVar4;
  }
  iVar2 = type_is_pointer_to_void(*g_call_context->formal);
  if (iVar2 == 0) {
    iVar2 = conv_check_conversion_to_type('p',*g_call_context->formal,node);
    if (iVar2 != 0) goto LAB_1061de4d;
    if (1 < g_call_context->call_depth) {
      diag_warning(1,0x59,g_call_context->name,g_call_context->nargs,g_call_context->call_depth);
      goto LAB_1061de4d;
    }
    iVar2 = g_call_context->nargs;
    pcVar9 = g_call_context->name;
    iVar8 = 0x18;
  }
  else {
    pcVar5 = node->type;
    if ((char)pcVar5->code < '\0') {
      iVar2 = conv_check_conversion_to_type('p',*g_call_context->formal,node);
      if (iVar2 != 0) goto LAB_1061de4d;
      if (1 < g_call_context->call_depth) {
        diag_warning(1,0x58,g_call_context->name,g_call_context->nargs,g_call_context->call_depth);
        goto LAB_1061de4d;
      }
    }
    else {
      if ((node->kind & 0x80) != 0) goto LAB_1061de4d;
      cVar1 = (char)pcVar5->code;
      while (cVar1 < '\0') {
        pcVar5 = pcVar5->base;
        cVar1 = (char)pcVar5->code;
      }
      iVar2 = g_call_context->call_depth;
      if ((pcVar5->code & 0x10) == 0) {
        if (iVar2 < 2) {
          diag_error(0xac,g_call_context->name,g_call_context->nargs);
        }
        else {
          diag_error(0xad,g_call_context->name,g_call_context->nargs,iVar2);
        }
        goto LAB_1061de4d;
      }
      if (1 < iVar2) {
        diag_warning(1,0x58,g_call_context->name,g_call_context->nargs,iVar2);
        goto LAB_1061de4d;
      }
    }
    iVar2 = g_call_context->nargs;
    pcVar9 = g_call_context->name;
    iVar8 = 0x16;
  }
  diag_warning(1,iVar8,pcVar9,iVar2);
LAB_1061de4d:
  pcVar3->type = *g_call_context->formal;
  if ((*g_call_context->formal)->code == 0x80d) {
    return pcVar3;
  }
  g_call_context->formal = g_call_context->formal + 1;
  g_call_context->nformals = g_call_context->nformals + -1;
  return pcVar3;
}

