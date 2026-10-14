char __thiscall tmpl_unify_parameter(c1_tmpl_deduction *this,c1_type *t,c1_type *type)

{
  byte bVar1;
  c1_arg_item *pcVar2;
  c1_arg_value cVar3;
  c1_deferred_detail cVar4;
  c1_node *src;
  c1_type *pcVar5;
  c1_deferred_action *pcVar6;
  ushort uVar9;
  byte bVar7;
  char cVar8;
  c1_type *pcVar10;
  c1_symbol *pcVar11;
  c1_node *pcVar12;
  uint uVar13;
  int iVar14;
  c1_deferred_action *binding_4;
  c1_sym_link *pcVar15;
  void *saved_24;
  void *pvVar16;
  c1_deferred_action *binding_2;
  int *piVar17;
  int *piVar18;
  char *pcVar19;
  int iVar20;
  c1_symbol *saved_0;
  int iVar21;
  c1_symbol *pcVar22;
  c1_u32 *pcVar23;
  c1_deferred_action *binding_3;
  c1_deferred_action *binding;
  
  this->cur_arg = (c1_arg_item *)0x0;
joined_r0x104a7f11:
  if ((c1_node *)type == (c1_node *)0x0) {
    diag_fatal(1,"..\\Cxx\\dymto.c",0x11de);
  }
  if ((this->flags & 0x40) == 0) {
    pcVar10 = type_skip_arrays(t);
    bVar7 = (byte)pcVar10->flags;
    pcVar12 = (c1_node *)type;
    if ((*(c1_u16 *)&((c1_node *)type)->op & 0x8f) == 0x83) {
      pcVar12 = (c1_node *)type_skip_arrays(((c1_node *)type)->type);
    }
    bVar1 = (byte)*(c1_u16 *)&pcVar12->flags;
    if ((bVar7 & 0x60) == 0) {
      if ((bVar1 & 0x60) != 0) {
        bVar7 = this->flags;
        goto joined_r0x104a80a4;
      }
    }
    else if (((bVar1 & 0x60) == 0) || ((bVar7 & 0x60) != (bVar1 & 0x60))) {
      bVar7 = this->flags;
joined_r0x104a80a4:
      if ((bVar7 & 0x10) != 0) {
        return '\0';
      }
    }
    else {
      type = type_strip_cv_qualifiers(type);
    }
  }
  uVar9 = t->code;
  if (((char)uVar9 < '\0') || ((uVar9 & 0xfff) != 0x801)) {
    if ((uVar9 & 0xfff) == 0x802) {
      return '\0';
    }
    if ((uVar9 & 0x200) == 0) {
      if (((char)uVar9 < '\0') && ((t->base->code & 0x200) != 0)) {
        saved_0 = (t->base->extra).cls;
      }
      else {
        saved_0 = (c1_symbol *)0x0;
      }
    }
    else {
      saved_0 = (t->extra).cls;
    }
    uVar9._0_1_ = ((c1_node *)type)->op;
    uVar9._1_1_ = ((c1_node *)type)->kind;
    if ((uVar9 & 0x200) == 0) {
      if (((char)(undefined1)uVar9 < '\0') && ((((c1_node *)type)->type->code & 0x200) != 0)) {
        pcVar22 = (((c1_node *)type)->type->extra).cls;
      }
      else {
        pcVar22 = (c1_symbol *)0x0;
      }
    }
    else {
      pcVar22 = (c1_symbol *)((c1_node *)type)->link;
    }
    bVar7 = ((saved_0->detail).cls)->flags3e;
    if ((bVar7 & 1) != 0) {
      if ((pcVar22 != (c1_symbol *)0x0) && ((((pcVar22->detail).cls)->flags3e & 1) != 0)) {
        saved_24 = tmpl_template_of_instance(saved_0);
        pvVar16 = tmpl_template_of_instance(pcVar22);
        if (saved_24 == pvVar16) {
          piVar17 = symtab_15f4_lookup(saved_0);
          piVar18 = symtab_15f4_lookup(pcVar22);
          iVar14 = *piVar17;
          iVar21 = *piVar18;
          this->flags = this->flags | 0x40;
          goto LAB_104a82da;
        }
      }
      binding_2 = arena_alloc(g_arenas + 5,0x14);
      if (binding_2 == (c1_deferred_action *)0x0) goto LAB_104a817a;
      cVar4 = (c1_deferred_detail)this->arg_type;
      pcVar10 = this->param_type;
      pcVar22 = this->tmpl;
      binding_2->next = (c1_deferred_action *)0x0;
      binding_2->sym = pcVar22;
      binding_2->arg = pcVar10;
      binding_2->detail = cVar4;
      binding_2->vtbl = &PTR_tmpl_deferred_report_c2784_104cee9c;
      goto LAB_104a8159;
    }
    if (pcVar22 == (c1_symbol *)0x0) {
LAB_104a8403:
      binding = (c1_deferred_action *)g_arenas[5].cur;
      g_arenas[5].cur = g_arenas[5].cur + 0x14;
      if (g_arenas[5].end < g_arenas[5].cur) {
        arena_grow(g_arenas + 5);
      }
      if (binding == (c1_deferred_action *)0x0) {
        binding = (c1_deferred_action *)0x0;
      }
      else {
        pcVar10 = this->arg_type;
        pcVar5 = this->param_type;
        pcVar22 = this->tmpl;
        *(c1_u8 *)((int)binding + 8) = '\0';
        *(c1_u8 *)((int)binding + 9) = '\0';
        *(c1_u8 *)((int)binding + 10) = '\0';
        *(c1_u8 *)((int)binding + 0xb) = '\0';
        *(c1_symbol **)((int)binding + 4) = pcVar22;
        *(c1_type **)((int)binding + 0xc) = pcVar5;
        *(c1_type **)((int)binding + 0x10) = pcVar10;
        binding->vtbl = &PTR_tmpl_deferred_report_c2784_104cee9c;
      }
      pcVar6 = binding;
      if (g_deferred_actions_head != (c1_deferred_action *)0x0) {
        g_deferred_actions_tail->next = binding;
        pcVar6 = g_deferred_actions_head;
      }
      g_deferred_actions_head = pcVar6;
      g_deferred_actions_tail = binding;
      this->flags = this->flags | 4;
      return '\0';
    }
    if ((((bVar7 & 2) != 0) && ((((pcVar22->detail).cls)->flags3e & 1) != 0)) &&
       (pcVar11 = tmpl_template_of_instance(pcVar22), saved_0 == pcVar11)) {
      return '\x01';
    }
    if (((saved_0->name != pcVar22->name) || (saved_0->scope_index == 0)) ||
       (((g_scope_vector->entries[(short)saved_0->scope_index]->kind & 0x1f) != 4 ||
        ((pcVar22->scope_index == 0 ||
         ((g_scope_vector->entries[(short)pcVar22->scope_index]->kind & 0x1f) != 4))))))
    goto LAB_104a8403;
    type = g_scope_vector->entries[(short)pcVar22->scope_index]->type;
    t = g_scope_vector->entries[(short)saved_0->scope_index]->type;
    this->cur_arg = (c1_arg_item *)0x0;
    goto joined_r0x104a7f11;
  }
  if (this->args == (c1_arg_list *)0x0) {
    return '\0';
  }
  uVar13 = *(ushort *)&t->extra & 0xff;
  this->cur_arg = this->args->first;
  while ((uVar13 = uVar13 - 1, 0 < (int)uVar13 && (this->cur_arg != (c1_arg_item *)0x0))) {
    this->cur_arg = this->cur_arg->next;
  }
  pcVar2 = this->cur_arg;
  if (pcVar2 == (c1_arg_item *)0x0) {
    binding_2 = arena_alloc(g_arenas + 5,0x14);
    if (binding_2 == (c1_deferred_action *)0x0) {
LAB_104a817a:
      binding_2 = (c1_deferred_action *)0x0;
    }
    else {
      cVar4 = (c1_deferred_detail)this->arg_type;
      pcVar10 = this->param_type;
      pcVar22 = this->tmpl;
      binding_2->next = (c1_deferred_action *)0x0;
      binding_2->sym = pcVar22;
      binding_2->arg = pcVar10;
      binding_2->detail = cVar4;
      binding_2->vtbl = &PTR_tmpl_deferred_report_c2784_104cee9c;
    }
LAB_104a8159:
    if (g_deferred_actions_head != (c1_deferred_action *)0x0) {
      g_deferred_actions_tail->next = binding_2;
      g_deferred_actions_tail = binding_2;
      return '\0';
    }
    g_deferred_actions_head = binding_2;
    g_deferred_actions_tail = binding_2;
    return '\0';
  }
  if ((pcVar2->value).type == (c1_type *)0x0) {
    (pcVar2->value).expr = (c1_node *)type;
    return '\x01';
  }
  if ((this->flags & 0x10) != 0) {
    type = type_strip_cv_qualifiers(type);
  }
  iVar14 = type_compare_template_instance_chain((this->cur_arg->value).type,type);
  if (iVar14 != 2) {
    return '\x01';
  }
  pcVar23 = (c1_u32 *)0x0;
  if (this->tparams == (c1_sym_list *)0x0) {
    pcVar15 = (c1_sym_link *)0x0;
  }
  else {
    pcVar15 = this->tparams->head;
  }
  if (pcVar15 != (c1_sym_link *)0x0) {
    while (((pcVar15->type).alias)->class_index != *(c1_u16 *)&t->extra) {
      if ((pcVar15 == (c1_sym_link *)0x0) ||
         (pcVar15 = pcVar15->next, pcVar15 == (c1_sym_link *)0x0)) goto LAB_104a81e1;
    }
    pcVar23 = &pcVar15[-1].position;
  }
LAB_104a81e1:
  binding_4 = arena_alloc(g_arenas + 5,0x18);
  if (binding_4 == (c1_deferred_action *)0x0) {
    binding_4 = (c1_deferred_action *)0x0;
  }
  else {
    cVar3 = this->cur_arg->value;
    binding_4->sym = this->tmpl;
    binding_4->next = (c1_deferred_action *)0x0;
    binding_4->arg = pcVar23;
    (binding_4->detail).type = type;
    binding_4->unk14 = (c1_u32)cVar3;
    binding_4->vtbl = &PTR_tmpl_deferred_report_c2782_104cee98;
  }
  if (g_deferred_actions_head != (c1_deferred_action *)0x0) {
    g_deferred_actions_tail->next = binding_4;
    g_deferred_actions_tail = binding_4;
    this->flags = this->flags | 8;
    return '\0';
  }
  g_deferred_actions_head = binding_4;
  g_deferred_actions_tail = binding_4;
  this->flags = this->flags | 8;
  return '\0';
LAB_104a82da:
  bVar7 = *(byte *)(iVar21 + 0xc) & 3;
  if (bVar7 == 0) {
    uVar9 = tmpl_type_find_parameter(*(c1_type **)(iVar14 + 0x10),1,0);
    if (uVar9 != 0) {
      cVar8 = tmpl_unify_parameter(this,*(c1_type **)(iVar14 + 0x10),*(c1_type **)(iVar21 + 0x10));
joined_r0x104a835b:
      if (cVar8 == '\0') {
        this->flags = this->flags & 0xbf;
        return '\0';
      }
    }
  }
  else if (bVar7 == 1) {
    pcVar12 = *(c1_node **)(iVar14 + 0x10);
    src = *(c1_node **)(iVar21 + 0x10);
    pcVar19 = tree_find_template_parameter_use((char *)pcVar12);
    if (pcVar19 != (char *)0x0) {
      iVar20 = tmpl_unify_constant_argument(this,pcVar12,src);
      cVar8 = (char)iVar20;
      goto joined_r0x104a835b;
    }
  }
  iVar14 = *(int *)(iVar14 + 4);
  iVar21 = *(int *)(iVar21 + 4);
  if ((iVar14 == 0) || (iVar21 == 0)) {
    this->flags = this->flags & 0xbf;
    binding_3 = (c1_deferred_action *)g_arenas[5].cur;
    if ((iVar14 == 0) && (iVar21 == 0)) {
      return '\x01';
    }
    g_arenas[5].cur = g_arenas[5].cur + 0x14;
    if (g_arenas[5].end < g_arenas[5].cur) {
      arena_grow(g_arenas + 5);
    }
    if (binding_3 == (c1_deferred_action *)0x0) {
      binding_3 = (c1_deferred_action *)0x0;
    }
    else {
      pcVar10 = this->arg_type;
      pcVar5 = this->param_type;
      pcVar22 = this->tmpl;
      *(c1_u8 *)((int)binding_3 + 8) = '\0';
      *(c1_u8 *)((int)binding_3 + 9) = '\0';
      *(c1_u8 *)((int)binding_3 + 10) = '\0';
      *(c1_u8 *)((int)binding_3 + 0xb) = '\0';
      *(c1_symbol **)((int)binding_3 + 4) = pcVar22;
      *(c1_type **)((int)binding_3 + 0xc) = pcVar5;
      *(c1_type **)((int)binding_3 + 0x10) = pcVar10;
      binding_3->vtbl = &PTR_tmpl_deferred_report_c2784_104cee9c;
    }
    if (g_deferred_actions_head != (c1_deferred_action *)0x0) {
      g_deferred_actions_tail->next = binding_3;
      g_deferred_actions_tail = binding_3;
      return '\0';
    }
    g_deferred_actions_head = binding_3;
    g_deferred_actions_tail = binding_3;
    return '\0';
  }
  goto LAB_104a82da;
}

