int __cdecl class_compare_members_by_name(c1_sym_link **a,c1_sym_link **b)

{
  if ((*a)->name < (*b)->name) {
    return -1;
  }
  return (uint)((*b)->name < (*a)->name);
}

