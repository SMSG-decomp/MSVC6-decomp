void __fastcall iv_retry_list_push(c2_tuple *t)

{
  g_iv_retry_list = list_node_push(g_iv_retry_list,t);
  return;
}

