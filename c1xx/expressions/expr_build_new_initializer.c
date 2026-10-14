c1_node * __cdecl
expr_build_new_initializer
          (char may_be_null,char vptr_stores,c1_symbol *cls,c1_node *object,c1_node *args,
          c1_symbol *target)

{
  c1_symbol *right;
  byte bVar1;
  char register_dtor;
  c1_node *pcVar2;
  c1_type *pcVar3;
  c1_conversion *conv;
  c1_type *pcVar4;
  c1_type local_10;
  c1_node *init_expr;
  
  pcVar2 = args;
  if (may_be_null == '\0') {
    if ((args != (c1_node *)0x0) && ((g_compile_flags_cc & 0x80000) != 0)) {
      init_expr = args->left;
      init_expr->link = (c1_node *)0x0;
      conv = (c1_conversion *)g_arenas[5].cur;
      if (g_ms_extensions == '\0') {
        g_arenas[5].cur = g_arenas[5].cur + 0x50;
        if (g_arenas[5].end < g_arenas[5].cur) {
          arena_grow(g_arenas + 5);
        }
        if (conv == (c1_conversion *)0x0) goto LAB_10478017;
        pcVar4 = cls->type;
        conv->op = 't';
        *(c1_u8 *)((int)conv + 1) = '\x02';
        *(c1_u8 *)((int)conv + 2) = '\0';
        *(c1_node **)((int)conv + 4) = init_expr;
        if (init_expr == (c1_node *)0x0) goto LAB_10477f8a;
        *(c1_type **)((int)conv + 8) = init_expr->type;
        *(c1_type **)((int)conv + 0xc) = pcVar4;
        conv_compute_conversion(conv);
      }
      else {
        g_arenas[5].cur = g_arenas[5].cur + 0x50;
        if (g_arenas[5].end < g_arenas[5].cur) {
          arena_grow(g_arenas + 5);
        }
        if (conv == (c1_conversion *)0x0) {
LAB_10478017:
          conv = (c1_conversion *)0x0;
        }
        else {
          pcVar4 = cls->type;
          conv->op = 't';
          *(c1_u8 *)((int)conv + 1) = '\x01';
          *(c1_u8 *)((int)conv + 2) = '\x02';
          *(c1_node **)((int)conv + 4) = init_expr;
          if (init_expr == (c1_node *)0x0) {
LAB_10477f8a:
            local_10.debug_index = 0;
            local_10.extra.cls = (c1_symbol *)0x0;
            local_10.base = (c1_type *)0x0;
            local_10.flags = 0;
            local_10.code = 0x80f;
            pcVar3 = type_intern(&local_10);
            *(c1_type **)((int)conv + 8) = pcVar3;
            *(c1_type **)((int)conv + 0xc) = pcVar4;
            conv_compute_conversion(conv);
          }
          else {
            *(c1_type **)((int)conv + 8) = init_expr->type;
            *(c1_type **)((int)conv + 0xc) = pcVar4;
            conv_compute_conversion(conv);
          }
        }
      }
      if ((conv->flags4e & 1) == 0) {
        conv_report_cannot_convert(conv,'\x01');
        return (c1_node *)0x0;
      }
      conv->target_kind = 0;
      conv->target_symbol = target;
      object = conv_apply_conversion(conv,object);
      goto LAB_1043d4e5;
    }
    if (((target == (c1_symbol *)0x0) || (bVar1 = target->storage & 7, bVar1 < 4)) || (6 < bVar1))
    goto LAB_1043d529;
    register_dtor = '\x01';
  }
  else {
    expr_make_reusable(&args,&object);
    if (vptr_stores != '\0') {
      target = (c1_symbol *)tree_copy_to_arena(object,g_expr_arena_index);
    }
LAB_1043d529:
    register_dtor = '\0';
  }
  object = expr_build_call_of((c1_symbol *)0x0,cls,object,pcVar2,'\0',1,register_dtor);
  if (object == (c1_node *)0x0) {
    return (c1_node *)0x0;
  }
LAB_1043d4e5:
  pcVar2 = expr_lvalue_address(object,0);
  right = target;
  if (pcVar2 == (c1_node *)0x0) {
    return (c1_node *)0x0;
  }
  if (may_be_null != '\0') {
    if (vptr_stores != '\0') {
      object = pcVar2;
      pcVar2 = class_build_vptr_stores((c1_node *)target,cls);
      object = tree_new_binary_typed_right('7',object,pcVar2);
      pcVar2 = tree_new_binary_typed_right('7',object,(c1_node *)right);
    }
    object = pcVar2;
    pcVar2 = expr_build_null_guarded(args,pcVar2);
  }
  return pcVar2;
}

