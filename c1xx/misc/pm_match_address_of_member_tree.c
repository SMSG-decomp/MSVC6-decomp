int __cdecl pm_match_address_of_member_tree(char *node,char **inner)

{
  char *pcVar1;
  char *pcVar2;
  char *pcVar3;
  
  while( true ) {
    if (node == (char *)0x0) {
      return 0;
    }
    if (*node != 'd') break;
    node = *(char **)(node + 0x10);
  }
  if (node == (char *)0x0) {
    return 0;
  }
  if (*node != '7') {
    return 0;
  }
  pcVar1 = *(char **)(node + 0x10);
  if (*pcVar1 != '7') {
    return 0;
  }
  pcVar2 = *(char **)(pcVar1 + 0x10);
  if (*pcVar2 != '4') {
    return 0;
  }
  pcVar3 = *(char **)(pcVar2 + 0x10);
  if (*pcVar3 != 'S') {
    return 0;
  }
  if (**(char **)(pcVar3 + 0x10) != -100) {
    return 0;
  }
  if (**(char **)(pcVar3 + 0x14) != 'e') {
    return 0;
  }
  pcVar2 = *(char **)(pcVar2 + 0x14);
  *inner = pcVar2;
  if (*pcVar2 != '\x06') {
    return 0;
  }
  pcVar1 = *(char **)(pcVar1 + 0x14);
  if (*pcVar1 != '4') {
    return 0;
  }
  pcVar2 = *(char **)(pcVar1 + 0x10);
  if (*pcVar2 != 'S') {
    return 0;
  }
  if (**(char **)(pcVar2 + 0x10) != -100) {
    return 0;
  }
  if (**(char **)(pcVar2 + 0x14) != 'e') {
    return 0;
  }
  if (**(char **)(pcVar1 + 0x14) != 'e') {
    return 0;
  }
  if (**(char **)(node + 0x14) != '=') {
    return 0;
  }
  if (**(char **)(*(char **)(node + 0x14) + 0x10) != -100) {
    return 0;
  }
  return 1;
}

