int __thiscall conv_compare_class_derivation(char flip,c1_symbol *class_a,c1_symbol *class_b)

{
  c1_symbol *pcVar1;
  
  if (class_a != class_b) {
    pcVar1 = class_lookup_qualified_member(g_current_scope,class_a,class_b,0);
    if (pcVar1 != (c1_symbol *)0x0) {
      return (-(uint)(flip != '\0') & 0xfffffffe) + 1;
    }
    pcVar1 = class_lookup_qualified_member(g_current_scope,class_b,class_a,0);
    if (pcVar1 != (c1_symbol *)0x0) {
      return (-(uint)(flip != '\0') & 2) - 1;
    }
  }
  return 0;
}

