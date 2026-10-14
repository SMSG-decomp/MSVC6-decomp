c1_node * __cdecl tree_new_string_literal(char *text)

{
  char cVar1;
  c1_node *literal;
  c1_node *pcVar2;
  c1_arena *a;
  int iVar3;
  char *pcVar4;
  
  a = g_arenas + g_expr_arena_index;
  literal = (c1_node *)a->cur;
  pcVar2 = (c1_node *)g_arenas[g_expr_arena_index].end;
  a->cur = &literal[1].op;
  if (pcVar2 < literal + 1) {
    arena_grow(a);
  }
  iVar3 = -1;
  literal->kind = '\x05';
  literal->op = '\a';
  pcVar4 = text;
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  *(ushort *)&literal->right = ~(ushort)iVar3;
  literal->left = text;
  type_string_literal_array(literal);
  return literal;
}

