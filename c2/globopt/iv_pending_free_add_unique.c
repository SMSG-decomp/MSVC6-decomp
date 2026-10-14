int __fastcall iv_pending_free_add_unique(c2_tuple *t)

{
  int iVar1;
  
  iVar1 = list_contains_value(g_iv_pending_free_list,(int)t);
  if (iVar1 == 0) {
    g_iv_pending_free_list = list_node_push(g_iv_pending_free_list,t);
    return 1;
  }
  return 0;
}

