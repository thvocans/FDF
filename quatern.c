/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quatern.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 17:29:45 by thvocans          #+#    #+#             */
/*   Updated: 2017/09/12 15:23:03 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

typedef struct s_vec3	t_vec3;
struct s_vec3
{
	double	x;
	double	y;
	double	z;
};

t_quat		rot_quat(double angle, int axe_x, int axe_y, int axe_z)
{
	t_quat q;
	
	angle = angle * (M_PI / 180);
	q.w = cosf(angle / 2);				//doubles
	q.x = axe_x * sinf(angle / 2);
	q.y = axe_y * sinf(angle / 2);
	q.z = axe_z * sinf(angle / 2);
	return (q);
}

t_quat		quat_inverse(t_quat q)
{
	q.x *= -1;
	q.y *= -1;
	q.z *= -1;
	return (q);
}

t_quat		quat_mult(t_quat q1, t_quat q2)
{
	t_quat q;

// www.gamedev.net/articles/programming/math-and-physics/quaternion-powers-r1095/
	q.w = (q1.w * q2.w) - (q1.x * q2.x) - (q1.y * q2.y) - (q1.z * q2.z);
	q.x = (q1.w * q2.x) + (q1.x * q2.w) + (q1.y * q2.z) - (q1.z * q2.y);
	q.y = (q1.w * q2.y) + (q1.y * q2.w) + (q1.z * q2.x) - (q1.x * q2.z);
	q.z = (q1.w * q2.z) + (q1.z * q2.w) + (q1.x * q2.y) - (q1.y * q2.x);
	return (q);
}

t_quat		pure_quat(int px_x, int px_y, int px_z) //3 Dim vector to quat
{
	t_quat pure;

	pure.w = 0;		// pure quat : w = 0;
	pure.x = px_x;
	pure.y = px_y;
	pure.z = px_z;
	return (pure);
}

double		vec_dot(t_quat u, t_quat v)
{
	return ((u.x * v.x) + (u.y * v.y) + (u.z * v.z));
}

t_quat	vec_cross(t_quat u, t_quat v)
{
	t_quat out;

	out.w = -1; 				// value for vec3 ??
	out.x = u.y * v.z - u.z * v.y;
	out.y = u.z * v.x - u.x * v.z;
	out.z = u.x * v.y - u.y * v.x;
	return (out);
}

t_quat		quat_rot(t_quat vec, t_quat rot)
{
	vec = quat_mult(vec, rot);					//clockwise
	vec = quat_mult(quat_inverse(rot), vec);	//clockwise
	return (vec);
}
/*
int main(int ac, char **av)
{
	t_quat q1;
	t_quat rot;
	t_quat rot2;
	t_quat tot;
	t_quat new;
	t_quat rotinv;

	q1 = pure_quat(10, 10, 5);
	rot = rot_quat(60, 1, 0, 0); // 60 deg to the back
	rot2 = rot_quat(15, 0, 0,1); // 15 deg counterclock

	rot = quat_mult(rot2, rot);
	new = quat_rot(q1, rot);

//	if (q1.z != 0)
//	{
//		q1.x /= q1.z;
//		q1.y /= q1.z;
//	}

//	printf("q1	w:%f x:%f y:%f z:%f\n",q1.w, q1.x, q1.y, q1.z);
	printf("ro3	w:%f x:%f y:%f z:%f\n",rot.w, rot.x, rot.y, rot.z);
//	printf("q1	w:%f x:%f y:%f z:%f\n",q1.w, q1.x, q1.y, q1.z);
	printf("new	w:%f x:%f y:%f z:%f\n",new.w, new.x, new.y, new.z);
}
*/
