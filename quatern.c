/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quatern.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 17:29:45 by thvocans          #+#    #+#             */
/*   Updated: 2017/09/05 23:13:13 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>

typedef struct s_quat	t_quat;
struct s_quat
{
	float	w;
	float	x;
	float	y;
	float	z;
};


t_quat		quat_rot(float angle, int axe_x, int axe_y, int axe_z)
{
	t_quat q;
	
	angle = angle * (M_PI / 180);
	q.w = cosf(angle / 2);				//floats
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


int main()
{
	t_quat q1;
	t_quat rot;

	q1.w = 1;
	q1.x = 10;
	q1.y = 10;
	q1.z = 5;
	

	rot = quat_rot(90, 0, 1, 0);
	q1 = quat_rot(45, 1, 0, 0);
	printf("q1	w:%f x:%f y:%f z:%f\n",q1.w, q1.x, q1.y, q1.z);
	printf("rot	w:%f x:%f y:%f z:%f\n",rot.w, rot.x, rot.y, rot.z);
	q1 = quat_mult(q1, rot);
	printf("out	w:%f x:%f y:%f z:%f\n",q1.w, q1.x, q1.y, q1.z);
}
