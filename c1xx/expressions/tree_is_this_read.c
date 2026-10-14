int __cdecl tree_is_this_read(c1_node *node)

{
  char *pcVar1;
  
  if ((node->kind & 7) != 1) {
    return 0;
  }
  pcVar1 = node->left;
  if (pcVar1 == (char *)0x0) {
    return 0;
  }
  if ((pcVar1[1] & 7U) != 4) {
    return 0;
  }
  if (*pcVar1 != -100) {
    return (uint)(*(int *)(*(int *)(pcVar1 + 0x10) + 8) == g_name_this);
  }
  return 0;
}

