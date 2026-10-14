c1_node * __cdecl
ovl_convert_call_arguments
          (c1_symbol *fn,c1_type *type,c1_node *args,c1_conversion *conversions,int argc)

{
  c1_type_list *pcVar1;
  c1_type *pcVar2;
  bool bVar3;
  c1_u8 *pcVar4;
  int iVar5;
  c1_node *pcVar6;
  c1_node *pcVar7;
  int argno;
  int iVar8;
  c1_node *list;
  c1_conversion *conv;
  c1_type **arg3;
  c1_type *word;
  
  argno = argc;
  bVar3 = false;
  pcVar1 = ((type->extra).params)->list;
  iVar8 = pcVar1->count;
  arg3 = pcVar1->types + iVar8 + -1;
  if ((iVar8 == 0) || ((iVar8 == 1 && (*arg3 == g_type_void)))) {
    if ((argc != 0) && ((*(byte *)((int)&fn->tail + 9) & 0x40) != 0)) {
      diag_error(0x294,fn->name->text,argc);
    }
    return args;
  }
  if (((*arg3)->code == 0x80d) && (argc < iVar8)) {
    arg3 = arg3 + -1;
    iVar8 = iVar8 + -1;
  }
  iVar5 = iVar8;
  pcVar7 = args;
  eh_enter_new_expression_region();
  if (argc < iVar8) {
    list = (c1_node *)0x0;
    iVar5 = iVar8 + -1;
    pcVar6 = ((type->extra).params)->defaults;
    iVar8 = (iVar5 - argc) + 1;
    do {
      if (*(char *)pcVar6->left == -0x3a) {
        default_argument_parse_deferred(fn,(int)arg3,(int)pcVar6);
      }
      list = eh_build_state_table(list,pcVar6->left);
      pcVar6 = pcVar6->right;
      arg3 = arg3 + -1;
      iVar8 = iVar8 + -1;
      iVar5 = iVar5 + -1;
    } while (iVar8 != 0);
    pcVar6 = list;
    if (args != (c1_node *)0x0) {
      pcVar6 = pcVar7;
    }
    list->link->link = pcVar6->link;
    pcVar7 = pcVar6;
    while (pcVar6 = list, pcVar6 != (c1_node *)0x0) {
      list = pcVar6->right;
      pcVar6->link = pcVar7->link;
      pcVar6->right = pcVar7;
      pcVar7->link = pcVar6;
      pcVar7 = pcVar6;
    }
    pcVar7->link->right = (void *)0x0;
  }
  pcVar4 = g_arenas[5].cur;
  if (args != (c1_node *)0x0) {
    argc._0_1_ = '\0';
    if (conversions == (c1_conversion *)0x0) {
      g_arenas[5].cur = g_arenas[5].cur + argno * 0x50;
      if (g_arenas[5].end < g_arenas[5].cur) {
        arena_grow(g_arenas + 5);
      }
      conv = (c1_conversion *)(pcVar4 + argno * 0x50 + -0x50);
      argc._0_1_ = '\x01';
    }
    else {
      conv = conversions + argno;
      if ((fn == (c1_symbol *)0x0) || ((fn->flags1 & 4) == 0)) {
        conv = conv + -1;
      }
    }
    for (; 0 < argno; argno = argno + -1) {
      pcVar6 = args->left;
      if ((pcVar6 == (c1_node *)0x0) || ((pcVar6->kind & 8) != 0)) {
        eh_leave_new_expression_region();
        return (c1_node *)0x0;
      }
      pcVar2 = *arg3;
      if ((pcVar2->code == 0x80d) && (iVar5 != argno)) {
LAB_1042ccae:
        if (conv == (c1_conversion *)0x0) {
          conv = (c1_conversion *)0x0;
        }
        else {
          conv->op = '`';
          conv->mode = '\x02';
          conv->flags = '\x04';
          conv->expr = pcVar6;
          word = pcVar6->type;
          conv->target = pcVar2;
          conv->source = word;
          conv_compute_conversion(conv);
        }
        if ((conv->flags4e & 1) == 0) {
          pcVar7 = ovl_report_parameter_conversion
                             (argno,conv,pcVar6,pcVar2,arg3,iVar5,pcVar7,fn,type,args,(char)argc);
          return pcVar7;
        }
      }
      else {
        arg3 = arg3 + -1;
        iVar5 = iVar5 + -1;
        if ((char)argc != '\0') goto LAB_1042ccae;
      }
      pcVar6 = conv_apply_conversion(conv,(c1_node *)0x0);
      args->left = pcVar6;
      if (pcVar6 == (c1_node *)0x0) {
        bVar3 = true;
      }
      else {
        pcVar6->link = args;
        if (pcVar2->code == 0x80d) {
          args->type = g_type_none;
        }
        else {
          args->type = pcVar6->type;
        }
      }
      args = args->right;
      conv = conv + -1;
    }
  }
  pcVar6 = eh_leave_new_expression_region();
  if (bVar3) {
    return (c1_node *)0x0;
  }
  if (pcVar6 == (c1_node *)0x0) {
    return pcVar7;
  }
  pcVar7 = tree_new_binary_typed_right('7',pcVar7,pcVar6);
  return pcVar7;
}

