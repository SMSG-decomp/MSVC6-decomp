c1_node * __cdecl
eh_build_exit_state_change(c1_node *left,int name,c1_flow_state *rec,c1_node *flag)

{
  int iVar1;
  byte bVar2;
  
  if (g_error_count != g_flow_error_count_at_start) {
    return left;
  }
  iVar1 = rec->kind;
  if (iVar1 == 5) {
    if ((rec->flags5 & 1) == 0) {
      bVar2 = g_current_function->flags1 & 0x10;
      if ((bVar2 == 0x10) && (g_eh_ctor_return_flushed == '\0')) {
        return left;
      }
      if ((bVar2 == 0x10) && (g_eh_ctor_return_flushed == '\x01')) {
        g_eh_unwind_form = '\0';
      }
    }
  }
  else {
    if (iVar1 == 0xd) {
      flag = tree_new_node_with_fields
                       ((g_eh_unwind_form == '\0') + 0xc2,1,(void *)rec->word1c,
                        -(ushort)(g_eh_unwind_form != '\0') & 0x80 |
                        -(ushort)((char)flag != '\0') & 0x20);
      g_eh_current_state = rec->word18;
      goto LAB_10449675;
    }
    if (iVar1 != 0xe) goto LAB_10449675;
  }
  flag = tree_new_node_with_fields
                   ((g_eh_unwind_form == '\0') + 0xc2,(ushort)rec->word1c,(void *)rec->word18,
                    -(ushort)(g_eh_unwind_form != '\0') & 0x80 |
                    -(ushort)((char)flag != '\0') & 0x20);
  g_eh_current_state = rec->word14;
LAB_10449675:
  if (left != (c1_node *)0x0) {
    flag = tree_new_binary_typed_right('7',left,flag);
  }
  if ((g_current_function->flags5 & 1) != 0) {
    diag_warning(3,0x1fd,g_current_function,name);
  }
  return flag;
}

