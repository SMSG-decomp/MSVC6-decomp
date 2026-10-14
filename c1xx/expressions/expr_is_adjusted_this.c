int __cdecl expr_is_adjusted_this(c1_node *node)

{
  char *pcVar1;
  byte bVar2;
  int iVar3;
  
  if ((((((node->op != 'F') || (*(char *)node->left != '=')) ||
        (pcVar1 = *(char **)((int)node->left + 0x10), *pcVar1 != '\x06')) ||
       ((*(int *)(*(int *)(pcVar1 + 0x10) + 8) != g_name_this ||
        (g_current_function == (c1_symbol *)0x0)))) ||
      ((bVar2 = g_current_function->kind & 0x1f, bVar2 != 7 && (bVar2 != 8)))) ||
     ((iVar3 = 1, (*(byte *)((int)&g_current_function->tail + 8) & 1) == 0 ||
      ((*(byte *)((int)&g_current_function->tail + 10) & 0x10) == 0)))) {
    iVar3 = 0;
  }
  return iVar3;
}

