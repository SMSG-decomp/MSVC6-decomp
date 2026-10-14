void __fastcall iv_worklist_push(c2_tuple *v)

{
  g_iv_worklist = list_node_push(g_iv_worklist,v);
  return;
}

