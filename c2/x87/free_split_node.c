void __fastcall free_split_node(void *n)

{
  void *pvVar1;
  
  pvVar1 = n;
  *(void **)n = g_split_node_free;
  g_split_node_free = pvVar1;
  return;
}

