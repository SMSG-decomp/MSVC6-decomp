char __fastcall class_name_is_current_class(c1_declarator *d)

{
  if (g_class_depth < 0) {
    return '\0';
  }
  return d->name == (g_class_def_stack[g_class_depth].cls)->name;
}

