bool __cdecl expr_same_based_base(c1_node *a,char *b)

{
  char *pcVar1;
  char *pcVar2;
  
  if (a == (c1_node *)b) {
    return true;
  }
  if ((((((a != (c1_node *)0x0) && (b != (char *)0x0)) && (a->kind == b[1])) &&
       ((a->op == *b && (a->op == '=')))) &&
      ((pcVar1 = a->left, pcVar1 != (char *)0x0 &&
       ((pcVar2 = *(char **)(b + 0x10), pcVar2 != (char *)0x0 && ((pcVar1[1] & 7U) == 4)))))) &&
     ((*pcVar1 == '\x06' && (((pcVar2[1] & 7U) == 4 && (*pcVar2 == '\x06')))))) {
    return *(int *)(pcVar1 + 0x10) == *(int *)(pcVar2 + 0x10);
  }
  return false;
}

