
#include "lem_in.h"

void     decide_path1(t_lst **tmp, char **st, t_lst **addr, t_lst **path)
{
    char **cut;

    cut = ft_strsplit((*tmp)->data, '-');
    create_path(path, cut[0]);
    if (duplicate2(*path, cut[0]))
        delete_node(path, ft_lstlen(*path));
    *st = cut[0];
    *addr = addr_pos(*tmp, loc(*tmp, *st));
}

void     decide_path2(t_lst **tmp, char **st, t_lst **addr, t_lst **path)
{
    char **cut;

    cut = ft_strsplit((*tmp)->data, '-');
    create_path(path, cut[1]);
    if (duplicate2(*path, cut[0]))
        delete_node(path, ft_lstlen(*path));
    *st = cut[1];
    *addr = addr_pos(*tmp, loc(*tmp, *st));
}

void     change_tmp_value(t_lst **tmp, t_lst *addr, t_lst **path, char **st)
{
    *tmp = addr->right;
    delete_node(path, loc(*path, pos(*path, ft_lstlen(*path)))-1);
    *st = pos(*path, ft_lstlen(*path));
}

t_lst    *top_bot(char *st, char *en, t_lst **path, t_lst *res)
{
    t_lst   *tmp;
    t_lst   *addr;
    char    **cut;
    char    *en1;

    tmp = res;
    en1 = ft_strdup(st); 
    while (tmp)
    {
        if (ft_strcmp(st,ft_strreturn(tmp->data, st)) == 0)
        {
            cut = ft_strsplit(tmp->data, '-');
            if (!ft_strcmp(cut[1], ft_strreturn(tmp->data, st)))
                does_link(res, st, en) == 1 ? create_path(path, en) : decide_path1(&tmp, &st, &addr, path);
            else
                does_link(res, st, en) == 1 ? create_path(path, en) : decide_path2(&tmp, &st, &addr, path);
            if (!ft_strcmp(pos(*path, ft_lstlen(*path)), en))
                break;
        }
        tmp = tmp->right;
        if (tmp == NULL && ft_strcmp(pos(*path, ft_lstlen(*path)), en))//the new start should match one of the next link rooms
        {
            if (((loc(res, en1) - 1) != ft_lstlen(res) && (loc(res, en1) - 1) != 1 && !(*path)->right) || !addr->right)
                break;
            change_tmp_value(&tmp, addr, path, &st);
        }
    }
    return (tmp);
}

t_lst    *bot_top (char *st, char *en, t_lst **path, t_lst *res)
{
    t_lst   *tmp;
    t_lst   *addr;
    char    **cut;
    char    *en1;

    tmp = addr_pos(res, ft_lstlen(res));
    en1 = ft_strdup(st); 
    while (tmp)
    {
        if (ft_strcmp(st,ft_strreturn(tmp->data, st)) == 0)
        {
            cut = ft_strsplit(tmp->data, '-');
            if (!ft_strcmp(cut[1], ft_strreturn(tmp->data, st)))
                does_link(res, st, en) == 1 ? create_path(path, en) : decide_path1(&tmp, &st, &addr, path);
            else
                does_link(res, st, en) == 1 ? create_path(path, en) : decide_path2(&tmp, &st, &addr, path);
            if (!ft_strcmp(pos(*path, ft_lstlen(*path)), en))
                break;
        }
        tmp = tmp->left;
        if (tmp == NULL && ft_strcmp(pos(*path, ft_lstlen(*path)), en))
        {
            if (((loc(res, en1) - 1) != ft_lstlen(res) && (loc(res, en1) - 1) != 1))
                tmp = addr_pos(res, ft_lstlen(res));
            else
                change_tmp_value(&tmp, addr, path, &st);
            st = pos(*path, ft_lstlen(*path));
        }
    }
    return (tmp);
}


